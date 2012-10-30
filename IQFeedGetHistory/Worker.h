/************************************************************************
 * Copyright(c) 2012, One Unified. All rights reserved.                 *
 * email: info@oneunified.net                                           *
 *                                                                      *
 * This file is provided as is WITHOUT ANY WARRANTY                     *
 *  without even the implied warranty of                                *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                *
 *                                                                      *
 * This software may not be used nor distributed without proper license *
 * agreement.                                                           *
 *                                                                      *
 * See the file LICENSE.txt for redistribution information.             *
 ************************************************************************/

#pragma once

// For IQFeedGetHistory

#include <string>

#include <boost/thread/thread.hpp>
//#include <boost/noncopyable.hpp>

class Worker {
public:
  explicit Worker( const std::string& sPrefixPath );
  ~Worker(void);
  void operator()( void );
  void Join( void ) { m_thread.join(); };
protected:
private:
  std::string m_sPrefixPath;
  boost::thread m_thread;
};

