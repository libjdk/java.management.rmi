#ifndef _javax_management_remote_rmi_RMIServer_h_
#define _javax_management_remote_rmi_RMIServer_h_
//$ interface javax.management.remote.rmi.RMIServer
//$ extends java.rmi.Remote

#include <java/rmi/Remote.h>

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {
				class RMIConnection;
			}
		}
	}
}

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

class $export RMIServer : public ::java::rmi::Remote {
	$interface(RMIServer, $NO_CLASS_INIT, ::java::rmi::Remote)
public:
	virtual $String* getVersion() {return nullptr;}
	virtual ::javax::management::remote::rmi::RMIConnection* newClient(Object$* credentials) {return nullptr;}
};

			} // rmi
		} // remote
	} // management
} // javax

#endif // _javax_management_remote_rmi_RMIServer_h_