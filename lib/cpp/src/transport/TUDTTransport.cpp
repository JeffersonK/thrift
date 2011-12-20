/*****************************************************************************
Copyright 2005 - 2011 The Board of Trustees of the University of Illinois.

Licensed under the Apache License, Version 2.0 (the "License"); you may not
use this file except in compliance with the License. You may obtain a copy of
the License at

   http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
License for the specific language governing permissions and limitations under
the License.
*****************************************************************************/

/*****************************************************************************
written by
   Yunhong Gu, last updated 01/02/2011
*****************************************************************************/


#ifndef WIN32
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#else
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#endif

#include <fstream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <transport/TUDTTransport.h>
#include <udt.h>
#include <udttransport.h>

namespace apache { namespace thrift { namespace transport {

      using namespace std;
      //using namespace UDT;

      TUDTTransport::TUDTTransport(boost::shared_ptr<TTransport> transport):      
	transport_(transport)
	{
	}

      TUDTTransport::~TUDTTransport()
      {
	close();
      }

      uint32_t TUDTTransport::read(uint8_t* buf, uint32_t len){
	return 0;
      }

      uint32_t TUDTTransport::readEnd(){
	return 0;
      }
      
      void TUDTTransport::write(const uint8_t* buf, uint32_t len){
      }

      void TUDTTransport::init(){
      }
    
    } } }//end of namespace
