#include <com/sun/jmx/remote/internal/rmi/RMIExporter.h>

#include <java/io/ObjectInputFilter.h>
#include <java/rmi/Remote.h>
#include <java/rmi/server/RMIClientSocketFactory.h>
#include <java/rmi/server/RMIServerSocketFactory.h>
#include <jcpp.h>

#undef EXPORTER_ATTRIBUTE

using $ObjectInputFilter = ::java::io::ObjectInputFilter;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Remote = ::java::rmi::Remote;
using $RMIClientSocketFactory = ::java::rmi::server::RMIClientSocketFactory;
using $RMIServerSocketFactory = ::java::rmi::server::RMIServerSocketFactory;

namespace com {
	namespace sun {
		namespace jmx {
			namespace remote {
				namespace internal {
					namespace rmi {

$FieldInfo _RMIExporter_FieldInfo_[] = {
	{"EXPORTER_ATTRIBUTE", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(RMIExporter, EXPORTER_ATTRIBUTE)},
	{}
};

$MethodInfo _RMIExporter_MethodInfo_[] = {
	{"exportObject", "(Ljava/rmi/Remote;ILjava/rmi/server/RMIClientSocketFactory;Ljava/rmi/server/RMIServerSocketFactory;Ljava/io/ObjectInputFilter;)Ljava/rmi/Remote;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.rmi.RemoteException"},
	{"unexportObject", "(Ljava/rmi/Remote;Z)Z", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.rmi.NoSuchObjectException"},
	{}
};

$ClassInfo _RMIExporter_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"com.sun.jmx.remote.internal.rmi.RMIExporter",
	nullptr,
	nullptr,
	_RMIExporter_FieldInfo_,
	_RMIExporter_MethodInfo_
};

$Object* allocate$RMIExporter($Class* clazz) {
	return $of($alloc(RMIExporter));
}

$String* RMIExporter::EXPORTER_ATTRIBUTE = nullptr;

void clinit$RMIExporter($Class* class$) {
	$assignStatic(RMIExporter::EXPORTER_ATTRIBUTE, "com.sun.jmx.remote.rmi.exporter"_s);
}

$Class* RMIExporter::load$($String* name, bool initialize) {
	$loadClass(RMIExporter, name, initialize, &_RMIExporter_ClassInfo_, clinit$RMIExporter, allocate$RMIExporter);
	return class$;
}

$Class* RMIExporter::class$ = nullptr;

					} // rmi
				} // internal
			} // remote
		} // jmx
	} // sun
} // com