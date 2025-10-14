#ifndef _com_sun_jmx_remote_internal_rmi_RMIExporter_h_
#define _com_sun_jmx_remote_internal_rmi_RMIExporter_h_
//$ interface com.sun.jmx.remote.internal.rmi.RMIExporter
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("EXPORTER_ATTRIBUTE")
#undef EXPORTER_ATTRIBUTE

namespace java {
	namespace io {
		class ObjectInputFilter;
	}
}
namespace java {
	namespace rmi {
		class Remote;
	}
}
namespace java {
	namespace rmi {
		namespace server {
			class RMIClientSocketFactory;
			class RMIServerSocketFactory;
		}
	}
}

namespace com {
	namespace sun {
		namespace jmx {
			namespace remote {
				namespace internal {
					namespace rmi {

class $import RMIExporter : public ::java::lang::Object {
	$interface(RMIExporter, 0, ::java::lang::Object)
public:
	virtual ::java::rmi::Remote* exportObject(::java::rmi::Remote* obj, int32_t port, ::java::rmi::server::RMIClientSocketFactory* csf, ::java::rmi::server::RMIServerSocketFactory* ssf, ::java::io::ObjectInputFilter* filter) {return nullptr;}
	virtual bool unexportObject(::java::rmi::Remote* obj, bool force) {return false;}
	static $String* EXPORTER_ATTRIBUTE;
};

					} // rmi
				} // internal
			} // remote
		} // jmx
	} // sun
} // com

#pragma pop_macro("EXPORTER_ATTRIBUTE")

#endif // _com_sun_jmx_remote_internal_rmi_RMIExporter_h_