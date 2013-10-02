/************************************************************************
 * Copyright(c) 2013, One Unified. All rights reserved.                 *
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

// Started 2013/09/21

#include <vector>

#include <boost/date_time/gregorian/gregorian_types.hpp>

namespace ou { // One Unified
namespace tf { // TradeFrame
namespace cboe {

    typedef std::vector<boost::gregorian::date> vExpiries_t;

    struct UnderlyingInfo {
      std::string sSymbol;
      std::string sDescription;
      std::string sProductType;
      boost::gregorian::date dateInitialList;
      bool rbExpires[6];
      UnderlyingInfo( void ) { for ( int ix = 0; ix < 6; ++ix ) rbExpires[ ix ] = false; };
    };
    typedef std::vector<UnderlyingInfo> vUnderlyinginfo_t;

    //std::vector<UnderlyingInfo> vui;

void ReadCboeWeeklyOptions( vExpiries_t& vExpiries, vUnderlyinginfo_t& vui );

} // namespace cboe  
} // namespace tf
} // namespace ou



// file link location to automatically retrieve:  
// http://www.cboe.com/micro/weeklys/availableweeklys.aspx

//      JAN 	FEB 	MAR 	APR 	MAY 	JUN 	JUL 	AUG 	SEP 	OCT 	NOV 	DEC
//CALLS 	A 	B 	C 	D 	E 	F 	G 	H 	I 	J 	K 	L
//PUTS 	M 	N 	O 	P 	Q 	R 	S 	T 	U 	V 	W 	X