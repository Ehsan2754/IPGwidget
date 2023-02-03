/**
 * @file IPGStreamThread.cpp
 * @author Ehsan Shaghaei @Ehsan2754
 * @brief Implementation of the IPGStreamThread class.
 * This file contains the declaration of the IPGStreamThread class which is responsible for writing 
 * values to a file in a separate thread. The class is also responsible for ensuring thread-safe 
 * access to the queue of values to be written.
 * @version 0.1
 * @date 2023-02-03
 * 
 * @copyright Copyright (c) 2023 Ehsan Shaghaei @Ehsan2754
 * 
 */

#include "IPGStreamThread.hpp"

#ifndef STREAM_PATH
#define STREAM_PATH "./messages.txt"
#endif

#ifndef PERIOD
#define PERIOD 5
#endif 


IPGStreamThread::IPGStreamThread() : m_stop(false), m_file(STREAM_PATH)
{
#ifdef USE_QT_THREAD
  connect(&m_qtThread, &QThread::started, this, &IPGStreamThread::threadRoutine);
#else
  m_thread = std::thread(&IPGStreamThread::threadRoutine, this);
#endif
}

IPGStreamThread::~IPGStreamThread()
{
  {
    std::unique_lock<std::mutex> lock(m_queueMutex);
    m_stop = true;
    m_queueCV.notify_one();
  }

#ifdef USE_QT_THREAD
  m_qtThread.quit();
  m_qtThread.wait();
#else
  m_thread.join();
#endif

  m_file.close();
}

void IPGStreamThread::addToQueue(const std::string& message)
{
  std::unique_lock<std::mutex> lock(m_queueMutex);
  m_queue.push(message);
  m_queueCV.notify_one();
}

void IPGStreamThread::threadRoutine()
{
  while (true)
  {
    std::unique_lock<std::mutex> lock(m_queueMutex);

    m_queueCV.wait(lock, [this]{ return m_stop || !m_queue.empty(); });

    if (m_stop)
    {
      break;
    }

    while (!m_queue.empty())
    {
      std::string message = m_queue.front();
      m_queue.pop();
      m_file << message << std::endl;
    }

#ifdef USE_QT_THREAD
    m_qtWaitCondition.wait(&m_qtMutex, PERIOD * 1000);
#else
    std::this_thread::sleep_for(std::chrono::seconds(PERIOD));
#endif
  }
}
