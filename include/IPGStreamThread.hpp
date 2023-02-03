/**
 * @file IPGStreamThread.hpp
 * @author Ehsan Shaghaei @Ehsan2754
 * @brief Declaration of the IPGStreamThread class.
 * This file contains the declaration of the IPGStreamThread class which is responsible for writing 
 * values to a file in a separate thread. The class is also responsible for ensuring thread-safe 
 * access to the queue of values to be written.
 * @version 0.1
 * @date 2023-02-03
 * 
 * @copyright Copyright (c) 2023 Ehsan Shaghaei @Ehsan2754
 * 
 */


#ifndef IPGSTREAMTHREAD_H
#define IPGSTREAMTHREAD_H

#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <fstream>
#include <chrono>

#ifdef USE_QT_THREAD
#include <QtCore/QThread>
#include <QtCore/QWaitCondition>
#include <QtCore/QMutex>
#endif

/**
 * @brief The IPGStreamThread class.
 *
 * This class is responsible for writing values to a file in a separate thread. The class is also 
 * responsible for ensuring thread-safe access to the queue of values to be written.
 */
class IPGStreamThread
{
private:
  std::mutex m_queueMutex; /**< Mutex for accessing the queue of values to be written. */
  std::condition_variable m_queueCV; /**< Condition variable for notifying the writing thread. */
  std::queue<std::string> m_queue; /**< Queue of values to be written to the file. */
  std::thread m_thread; /**< Thread for writing values to the file. */
  std::ofstream m_file; /**< Output file stream for writing values. */
  bool m_stop; /**< Flag for stopping the writing thread. */

#ifdef USE_QT_THREAD
  QThread m_qtThread; /**< Qt thread for writing values to the file. */
  QWaitCondition m_qtWaitCondition; /**< Qt wait condition for waiting between writes. */
  QMutex m_qtMutex; /**< Qt mutex for accessing the queue of values to be written. */
#endif

public:
  /**
   * @brief Constructor for IPGStreamThread class.
   *
   * This constructor initializes the IPGStreamThread object and starts the thread for writing 
   * values to the file.
   */
  IPGStreamThread();

  /**
   * @brief Destructor for IPGStreamThread class.
   *
   * This destructor stops the thread for writing values to the file and closes the output file 
   * stream.
   */
  ~IPGStreamThread();

  /**
   * @brief Add a value to the queue to be written to the file.
   * @param message The message to be added to the queue.
   */
  void addToQueue(const std::string& message);

private:
  /**
   * @brief Routine for the writing thread.
   *
   * This function is executed in the writing thread and is responsible for writing values from 
   * the queue to the file. The function ensures thread-safe access to the queue of values to be 
   * written.
   */
  void threadRoutine();
};

#endif // IPGSTREAMTHREAD_H
