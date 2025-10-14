#ifndef _javax_management_remote_rmi_RMIConnectionImpl$PrivilegedOperation_h_
#define _javax_management_remote_rmi_RMIConnectionImpl$PrivilegedOperation_h_
//$ class javax.management.remote.rmi.RMIConnectionImpl$PrivilegedOperation
//$ extends java.security.PrivilegedExceptionAction

#include <java/lang/Array.h>
#include <java/security/PrivilegedExceptionAction.h>

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

class RMIConnectionImpl$PrivilegedOperation : public ::java::security::PrivilegedExceptionAction {
	$class(RMIConnectionImpl$PrivilegedOperation, $NO_CLASS_INIT, ::java::security::PrivilegedExceptionAction)
public:
	RMIConnectionImpl$PrivilegedOperation();
	void init$(::javax::management::remote::rmi::RMIConnectionImpl* this$0, int32_t operation, $ObjectArray* params);
	virtual $Object* run() override;
	::javax::management::remote::rmi::RMIConnectionImpl* this$0 = nullptr;
	int32_t operation = 0;
	$ObjectArray* params = nullptr;
};

			} // rmi
		} // remote
	} // management
} // javax

#endif // _javax_management_remote_rmi_RMIConnectionImpl$PrivilegedOperation_h_