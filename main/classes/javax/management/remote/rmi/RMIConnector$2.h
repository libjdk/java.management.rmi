#ifndef _javax_management_remote_rmi_RMIConnector$2_h_
#define _javax_management_remote_rmi_RMIConnector$2_h_
//$ class javax.management.remote.rmi.RMIConnector$2
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace java {
	namespace lang {
		class Thread;
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

class RMIConnector$2 : public ::java::security::PrivilegedAction {
	$class(RMIConnector$2, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	RMIConnector$2();
	void init$(::javax::management::remote::rmi::RMIConnector* this$0, $Thread* val$t);
	virtual $Object* run() override;
	::javax::management::remote::rmi::RMIConnector* this$0 = nullptr;
	$Thread* val$t = nullptr;
};

			} // rmi
		} // remote
	} // management
} // javax

#endif // _javax_management_remote_rmi_RMIConnector$2_h_