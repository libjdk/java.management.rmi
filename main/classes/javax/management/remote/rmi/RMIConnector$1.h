#ifndef _javax_management_remote_rmi_RMIConnector$1_h_
#define _javax_management_remote_rmi_RMIConnector$1_h_
//$ class javax.management.remote.rmi.RMIConnector$1
//$ extends java.security.PrivilegedExceptionAction

#include <java/lang/Array.h>
#include <java/security/PrivilegedExceptionAction.h>

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

class RMIConnector$1 : public ::java::security::PrivilegedExceptionAction {
	$class(RMIConnector$1, 0, ::java::security::PrivilegedExceptionAction)
public:
	RMIConnector$1();
	void init$($bytes* val$pRefByteCode);
	virtual $Object* run() override;
	$bytes* val$pRefByteCode = nullptr;
	static bool $assertionsDisabled;
};

			} // rmi
		} // remote
	} // management
} // javax

#endif // _javax_management_remote_rmi_RMIConnector$1_h_