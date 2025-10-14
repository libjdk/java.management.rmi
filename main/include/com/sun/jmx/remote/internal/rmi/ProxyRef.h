#ifndef _com_sun_jmx_remote_internal_rmi_ProxyRef_h_
#define _com_sun_jmx_remote_internal_rmi_ProxyRef_h_
//$ class com.sun.jmx.remote.internal.rmi.ProxyRef
//$ extends java.rmi.server.RemoteRef

#include <java/lang/Array.h>
#include <java/rmi/server/RemoteRef.h>

namespace java {
	namespace io {
		class ObjectInput;
		class ObjectOutput;
	}
}
namespace java {
	namespace lang {
		namespace reflect {
			class Method;
		}
	}
}
namespace java {
	namespace rmi {
		class Remote;
	}
}
namespace java {
	namespace rmi {
		namespace server {
			class Operation;
			class RemoteCall;
			class RemoteObject;
		}
	}
}

namespace com {
	namespace sun {
		namespace jmx {
			namespace remote {
				namespace internal {
					namespace rmi {

class $import ProxyRef : public ::java::rmi::server::RemoteRef {
	$class(ProxyRef, $NO_CLASS_INIT, ::java::rmi::server::RemoteRef)
public:
	ProxyRef();
	void init$(::java::rmi::server::RemoteRef* ref);
	virtual void done(::java::rmi::server::RemoteCall* call) override;
	virtual $String* getRefClass(::java::io::ObjectOutput* out) override;
	virtual void invoke(::java::rmi::server::RemoteCall* call) override;
	virtual $Object* invoke(::java::rmi::Remote* obj, ::java::lang::reflect::Method* method, $ObjectArray* params, int64_t opnum) override;
	virtual ::java::rmi::server::RemoteCall* newCall(::java::rmi::server::RemoteObject* obj, $Array<::java::rmi::server::Operation>* op, int32_t opnum, int64_t hash) override;
	virtual void readExternal(::java::io::ObjectInput* in) override;
	virtual bool remoteEquals(::java::rmi::server::RemoteRef* obj) override;
	virtual int32_t remoteHashCode() override;
	virtual $String* remoteToString() override;
	virtual void writeExternal(::java::io::ObjectOutput* out) override;
	static const int64_t serialVersionUID = (int64_t)0xA5C07C245C1EAE7D;
	::java::rmi::server::RemoteRef* ref = nullptr;
};

					} // rmi
				} // internal
			} // remote
		} // jmx
	} // sun
} // com

#endif // _com_sun_jmx_remote_internal_rmi_ProxyRef_h_