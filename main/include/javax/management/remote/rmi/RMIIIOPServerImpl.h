#ifndef _javax_management_remote_rmi_RMIIIOPServerImpl_h_
#define _javax_management_remote_rmi_RMIIIOPServerImpl_h_
//$ class javax.management.remote.rmi.RMIIIOPServerImpl
//$ extends javax.management.remote.rmi.RMIServerImpl

#include <javax/management/remote/rmi/RMIServerImpl.h>

namespace java {
	namespace rmi {
		class Remote;
	}
}
namespace java {
	namespace util {
		class Map;
	}
}
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
	namespace security {
		namespace auth {
			class Subject;
		}
	}
}

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

class $import RMIIIOPServerImpl : public ::javax::management::remote::rmi::RMIServerImpl {
	$class(RMIIIOPServerImpl, $NO_CLASS_INIT, ::javax::management::remote::rmi::RMIServerImpl)
public:
	RMIIIOPServerImpl();
	void init$(::java::util::Map* env);
	virtual void closeClient(::javax::management::remote::rmi::RMIConnection* client) override;
	virtual void closeServer() override;
	virtual ::javax::management::remote::rmi::RMIConnection* doNewClient(Object$* credentials) override;
	virtual void export$() override;
	virtual $String* getProtocol() override;
	virtual ::javax::management::remote::rmi::RMIConnection* makeClient($String* connectionId, ::javax::security::auth::Subject* subject) override;
	virtual ::java::rmi::Remote* toStub() override;
};

			} // rmi
		} // remote
	} // management
} // javax

#endif // _javax_management_remote_rmi_RMIIIOPServerImpl_h_