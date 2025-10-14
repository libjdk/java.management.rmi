#ifndef _javax_management_remote_rmi_RMIJRMPServerImpl_h_
#define _javax_management_remote_rmi_RMIJRMPServerImpl_h_
//$ class javax.management.remote.rmi.RMIJRMPServerImpl
//$ extends javax.management.remote.rmi.RMIServerImpl

#include <javax/management/remote/rmi/RMIServerImpl.h>

namespace java {
	namespace io {
		class ObjectInputFilter;
		class ObjectInputFilter$FilterInfo;
		class ObjectInputFilter$Status;
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
namespace java {
	namespace util {
		class Map;
		class Set;
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

class $import RMIJRMPServerImpl : public ::javax::management::remote::rmi::RMIServerImpl {
	$class(RMIJRMPServerImpl, $NO_CLASS_INIT, ::javax::management::remote::rmi::RMIServerImpl)
public:
	RMIJRMPServerImpl();
	void init$(int32_t port, ::java::rmi::server::RMIClientSocketFactory* csf, ::java::rmi::server::RMIServerSocketFactory* ssf, ::java::util::Map* env);
	virtual void closeClient(::javax::management::remote::rmi::RMIConnection* client) override;
	virtual void closeServer() override;
	virtual void export$() override;
	void export$(::java::rmi::Remote* obj, ::java::io::ObjectInputFilter* typeFilter);
	virtual $String* getProtocol() override;
	static bool lambda$new$0($String* s);
	virtual ::javax::management::remote::rmi::RMIConnection* makeClient($String* connectionId, ::javax::security::auth::Subject* subject) override;
	virtual ::java::io::ObjectInputFilter$Status* newClientCheckInput(::java::io::ObjectInputFilter$FilterInfo* filterInfo);
	virtual ::java::rmi::Remote* toStub() override;
	void unexport(::java::rmi::Remote* obj, bool force);
	int32_t port = 0;
	::java::rmi::server::RMIClientSocketFactory* csf = nullptr;
	::java::rmi::server::RMIServerSocketFactory* ssf = nullptr;
	::java::util::Map* env = nullptr;
	::java::util::Set* allowedTypes = nullptr;
	::java::io::ObjectInputFilter* jmxRmiFilter = nullptr;
	::java::io::ObjectInputFilter* cFilter = nullptr;
};

			} // rmi
		} // remote
	} // management
} // javax

#endif // _javax_management_remote_rmi_RMIJRMPServerImpl_h_