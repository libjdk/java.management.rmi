#ifndef _javax_management_remote_rmi_RMIConnector$RMIClientCommunicatorAdmin_h_
#define _javax_management_remote_rmi_RMIConnector$RMIClientCommunicatorAdmin_h_
//$ class javax.management.remote.rmi.RMIConnector$RMIClientCommunicatorAdmin
//$ extends com.sun.jmx.remote.internal.ClientCommunicatorAdmin

#include <com/sun/jmx/remote/internal/ClientCommunicatorAdmin.h>
#include <java/lang/Array.h>

namespace com {
	namespace sun {
		namespace jmx {
			namespace remote {
				namespace internal {
					class ClientListenerInfo;
				}
			}
		}
	}
}
namespace java {
	namespace io {
		class IOException;
	}
}
namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {
				class RMIConnector;
			}
		}
	}
}

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

class RMIConnector$RMIClientCommunicatorAdmin : public ::com::sun::jmx::remote::internal::ClientCommunicatorAdmin {
	$class(RMIConnector$RMIClientCommunicatorAdmin, $NO_CLASS_INIT, ::com::sun::jmx::remote::internal::ClientCommunicatorAdmin)
public:
	RMIConnector$RMIClientCommunicatorAdmin();
	void init$(::javax::management::remote::rmi::RMIConnector* this$0, int64_t period);
	virtual void checkConnection() override;
	virtual void doStart() override;
	virtual void doStop() override;
	virtual void gotIOException(::java::io::IOException* ioe) override;
	virtual void reconnectNotificationListeners($Array<::com::sun::jmx::remote::internal::ClientListenerInfo>* old);
	::javax::management::remote::rmi::RMIConnector* this$0 = nullptr;
};

			} // rmi
		} // remote
	} // management
} // javax

#endif // _javax_management_remote_rmi_RMIConnector$RMIClientCommunicatorAdmin_h_