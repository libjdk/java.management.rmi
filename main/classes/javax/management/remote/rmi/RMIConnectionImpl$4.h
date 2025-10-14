#ifndef _javax_management_remote_rmi_RMIConnectionImpl$4_h_
#define _javax_management_remote_rmi_RMIConnectionImpl$4_h_
//$ class javax.management.remote.rmi.RMIConnectionImpl$4
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

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

class RMIConnectionImpl$4 : public ::java::security::PrivilegedAction {
	$class(RMIConnectionImpl$4, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	RMIConnectionImpl$4();
	void init$(::javax::management::remote::rmi::RMIConnectionImpl* this$0, int64_t val$csn, int64_t val$t, int32_t val$mn);
	virtual $Object* run() override;
	::javax::management::remote::rmi::RMIConnectionImpl* this$0 = nullptr;
	int32_t val$mn = 0;
	int64_t val$t = 0;
	int64_t val$csn = 0;
};

			} // rmi
		} // remote
	} // management
} // javax

#endif // _javax_management_remote_rmi_RMIConnectionImpl$4_h_