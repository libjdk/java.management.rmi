#ifndef _javax_management_remote_rmi_RMIConnectionImpl$5_h_
#define _javax_management_remote_rmi_RMIConnectionImpl$5_h_
//$ class javax.management.remote.rmi.RMIConnectionImpl$5
//$ extends java.security.PrivilegedExceptionAction

#include <java/security/PrivilegedExceptionAction.h>

namespace javax {
	namespace management {
		class ObjectName;
	}
}
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

class RMIConnectionImpl$5 : public ::java::security::PrivilegedExceptionAction {
	$class(RMIConnectionImpl$5, $NO_CLASS_INIT, ::java::security::PrivilegedExceptionAction)
public:
	RMIConnectionImpl$5();
	void init$(::javax::management::remote::rmi::RMIConnectionImpl* this$0, ::javax::management::ObjectName* val$name);
	virtual $Object* run() override;
	::javax::management::remote::rmi::RMIConnectionImpl* this$0 = nullptr;
	::javax::management::ObjectName* val$name = nullptr;
};

			} // rmi
		} // remote
	} // management
} // javax

#endif // _javax_management_remote_rmi_RMIConnectionImpl$5_h_