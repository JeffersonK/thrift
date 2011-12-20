
#ifndef _THRIFT_TRANSPORT_TUDTTRANSPORT_H_
#define _THRIFT_TRANSPORT_TUDTTRANSPORT_H_ 1

#include <transport/TBufferTransports.h>
#include "TVirtualTransport.h"
#include <udt.h>
#include <udttransport.h>

namespace apache { namespace thrift { namespace transport {

      /**
       * UDT implementation of the thrift transport. This was irritating
       * to write, but the alternatives in C++ land are daunting.
       */

      class TUDTTransport : public TVirtualTransport<TUDTTransport> {
      private:
	sector::UDTTransport udt;

      public:
	TUDTTransport(boost::shared_ptr<TTransport> transport);
	
	virtual ~TUDTTransport();

	void open() {
	  transport_->open();
	}
	
	bool isOpen() {
	  return transport_->isOpen();
	}

	bool peek() {
	  return transport_->peek();
	}

	void close() {
	  transport_->close();
	}

	uint32_t read(uint8_t* buf, uint32_t len);

	uint32_t readEnd();

	void write(const uint8_t* buf, uint32_t len);

	virtual void flush() = 0;

      protected:

	boost::shared_ptr<TTransport> transport_;

	virtual void init();
      };

    }}} // apache::thrift::transport

#endif // #ifndef _THRIFT_TRANSPORT_TUDTTRANSPORT_H_
