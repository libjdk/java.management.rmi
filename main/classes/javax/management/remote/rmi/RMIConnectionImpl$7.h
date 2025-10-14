#ifndef _javax_management_remote_rmi_RMIConnectionImpl$7_h_
#define _javax_management_remote_rmi_RMIConnectionImpl$7_h_
//$ class javax.management.remote.rmi.RMIConnectionImpl$7
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
				class RMIConnectionImpl;
			}
		}
	}
}

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

class RMIConnectionImpl$7 : public ::java::security::PrivilegedExceptionAction {
	$class(RMIConnectionImpl$7, $NO_CLASS_INIT, ::java::security::PrivilegedExceptionAction)
public:
	RMIConnectionImpl$7();
	void init$(::javax::management::remote::rmi::RMIConnectionImpl* this$0, ::java::lang::ClassLoader* val$cl1, ::java::lang::ClassLoader* val$cl2);
	virtual $Object* run() override;
	::javax::management::remote::rmi::RMIConnectionImpl* this$0 = nullptr;
	::java::lang::ClassLoader* val$cl2 = nullptr;
	::java::lang::ClassLoader* val$cl1 = nullptr;
};

			} // rmi
		} // remote
	} // management
} // javax

#endif // _javax_management_remote_rmi_RMIConnectionImpl$7_h_