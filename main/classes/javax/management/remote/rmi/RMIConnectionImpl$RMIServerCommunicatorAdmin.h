#ifndef _javax_management_remote_rmi_RMIConnectionImpl$RMIServerCommunicatorAdmin_h_
#define _javax_management_remote_rmi_RMIConnectionImpl$RMIServerCommunicatorAdmin_h_
//$ class javax.management.remote.rmi.RMIConnectionImpl$RMIServerCommunicatorAdmin
//$ extends com.sun.jmx.remote.internal.ServerCommunicatorAdmin

#include <com/sun/jmx/remote/internal/ServerCommunicatorAdmin.h>

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {
				class RMIConnectionImpl;
			}
		}
	}
}

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

class RMIConnectionImpl$RMIServerCommunicatorAdmin : public ::com::sun::jmx::remote::internal::ServerCommunicatorAdmin {
	$class(RMIConnectionImpl$RMIServerCommunicatorAdmin, $NO_CLASS_INIT, ::com::sun::jmx::remote::internal::ServerCommunicatorAdmin)
public:
	RMIConnectionImpl$RMIServerCommunicatorAdmin();
	void init$(::javax::management::remote::rmi::RMIConnectionImpl* this$0, int64_t timeout);
	virtual void doStop() override;
	::javax::management::remote::rmi::RMIConnectionImpl* this$0 = nullptr;
};

			} // rmi
		} // remote
	} // management
} // javax

#endif // _javax_management_remote_rmi_RMIConnectionImpl$RMIServerCommunicatorAdmin_h_