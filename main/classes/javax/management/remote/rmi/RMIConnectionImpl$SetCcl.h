#ifndef _javax_management_remote_rmi_RMIConnectionImpl$SetCcl_h_
#define _javax_management_remote_rmi_RMIConnectionImpl$SetCcl_h_
//$ class javax.management.remote.rmi.RMIConnectionImpl$SetCcl
//$ extends java.security.PrivilegedExceptionAction

#include <java/security/PrivilegedExceptionAction.h>

namespace java {
	namespace lang {
		class ClassLoader;
	}
}

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

class RMIConnectionImpl$SetCcl : public ::java::security::PrivilegedExceptionAction {
	$class(RMIConnectionImpl$SetCcl, $NO_CLASS_INIT, ::java::security::PrivilegedExceptionAction)
public:
	RMIConnectionImpl$SetCcl();
	void init$(::java::lang::ClassLoader* classLoader);
	virtual $Object* run() override;
	::java::lang::ClassLoader* classLoader = nullptr;
};

			} // rmi
		} // remote
	} // management
} // javax

#endif // _javax_management_remote_rmi_RMIConnectionImpl$SetCcl_h_