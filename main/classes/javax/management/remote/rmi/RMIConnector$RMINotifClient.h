#ifndef _javax_management_remote_rmi_RMIConnector$RMINotifClient_h_
#define _javax_management_remote_rmi_RMIConnector$RMINotifClient_h_
//$ class javax.management.remote.rmi.RMIConnector$RMINotifClient
//$ extends com.sun.jmx.remote.internal.ClientNotifForwarder

#include <com/sun/jmx/remote/internal/ClientNotifForwarder.h>

namespace java {
	namespace io {
		class IOException;
	}
}
namespace java {
	namespace lang {
		class ClassLoader;
		class Integer;
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
			class NotificationResult;
		}
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

class RMIConnector$RMINotifClient : public ::com::sun::jmx::remote::internal::ClientNotifForwarder {
	$class(RMIConnector$RMINotifClient, $NO_CLASS_INIT, ::com::sun::jmx::remote::internal::ClientNotifForwarder)
public:
	RMIConnector$RMINotifClient();
	void init$(::javax::management::remote::rmi::RMIConnector* this$0, ::java::lang::ClassLoader* cl, ::java::util::Map* env);
	virtual ::java::lang::Integer* addListenerForMBeanRemovedNotif() override;
	virtual ::javax::management::remote::NotificationResult* fetchNotifs(int64_t clientSequenceNumber, int32_t maxNotifications, int64_t timeout) override;
	virtual void lostNotifs($String* message, int64_t number) override;
	virtual void removeListenerForMBeanRemovedNotif(::java::lang::Integer* id) override;
	void rethrowDeserializationException(::java::io::IOException* ioe);
	::javax::management::remote::rmi::RMIConnector* this$0 = nullptr;
};

			} // rmi
		} // remote
	} // management
} // javax

#endif // _javax_management_remote_rmi_RMIConnector$RMINotifClient_h_