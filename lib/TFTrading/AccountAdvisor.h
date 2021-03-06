/************************************************************************
 * Copyright(c) 2010, One Unified. All rights reserved.                 *
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

#include <string>

#include <boost/shared_ptr.hpp>

#include <OUSQL/Functions.h>

#include "KeyTypes.h"

namespace ou { // One Unified
namespace tf { // TradeFrame

class AccountAdvisor
{
//  friend class CAccountManager;

public:

  typedef keytypes::idAccountAdvisor_t idAccountAdvisor_t;
  typedef boost::shared_ptr<AccountAdvisor> pAccountAdvisor_t;
  typedef pAccountAdvisor_t sharedptr_t;

  struct TableRowDef {
    template<class A>
    void Fields( A& a ) {
      ou::db::Field( a, "accountadvisorid", idAccountAdvisor );  // needs to be unique in database
      ou::db::Field( a, "name", sName );
      ou::db::Field( a, "company", sCompanyName );
    }

    idAccountAdvisor_t idAccountAdvisor;
    std::string sName;
    std::string sCompanyName;

    TableRowDef( void ) {};
    TableRowDef( 
      const idAccountAdvisor_t& idAdvisor_, const std::string& sName_, const std::string& sCompanyName_ ) 
      : idAccountAdvisor( idAdvisor_ ), sName( sName_ ), sCompanyName( sCompanyName_ ) {};
  };

  struct TableCreateDef: TableRowDef {
    template<class A>
    void Fields( A& a ) {
      TableRowDef::Fields( a );
      ou::db::Key( a, "accountadvisorid" );
    }
  };

  const static std::string m_sTableName;

  AccountAdvisor( 
    const idAccountAdvisor_t& sAdvisorId, 
    const std::string& sAdvisorName, const std::string& sCompanyName );
  AccountAdvisor( const TableRowDef& row );
  ~AccountAdvisor(void);

  const idAccountAdvisor_t& GetId( void ) const { 
    return m_row.idAccountAdvisor; 
  }

  const std::string& GetName( void ) const { 
    return m_row.sName; 
  }

  const std::string& GetCompanyName( void ) const {
    return m_row.sCompanyName;
  }

  const TableRowDef& GetRow( void ) const { return m_row; };

protected:

private:

  TableRowDef m_row;

  AccountAdvisor( void );  // no default constructor
};

} // namespace tf
} // namespace ou

