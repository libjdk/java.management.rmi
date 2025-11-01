#ifndef _javax_management_remote_rmi_RMIServerImpl_Stub_h_
#define _javax_management_remote_rmi_RMIServerImpl_Stub_h_
//$ class javax.management.remote.rmi.RMIServerImpl_Stub
//$ extends java.rmi.server.RemoteStub
//$ implements javax.management.remote.rmi.RMIServer

#include <java/rmi/server/RemoteStub.h>
#include <javax/management/remote/rmi/RMIServer.h>

namespace java {
	namespace lang {
		namespace reflect {
			class Method;
		}
	}
}
namespace java {
	namespace rmi {
		namespace server {
			class RemoteRef;
		}
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
	namespace management {
		namespace remote {
			namespace rmi {

class $import RMIServerImpl_Stub : public ::java::rmi::server::RemoteStub, public ::javax::management::remote::rmi::RMIServer {
	$class(RMIServerImpl_Stub, 0, ::java::rmi::server::RemoteStub, ::javax::management::remote::rmi::RMIServer)
public:
	RMIServerImpl_Stub();
	virtual $Object* clone() override;
	virtual bool equals(Object$* arg0) override;
	virtual void finalize() override;
	virtual int32_t hashCode() override;
	void init$(::java::rmi::server::RemoteRef* ref);
	virtual $String* getVersion() override;
	virtual ::javax::management::remote::rmi::RMIConnection* newClient(Object$* $param_Object_1) override;
	virtual $String* toString() override;
	static const int64_t serialVersionUID = 2;
	static ::java::lang::reflect::Method* $method_getVersion_0;
	static ::java::lang::reflect::Method* $method_newClient_1;
};

			} // rmi
		} // remote
	} // management
} // javax

#endif // _javax_management_remote_rmi_RMIServerImpl_Stub_h_