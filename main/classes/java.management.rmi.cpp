#include <java.management.rmi.h>

#include <java.naming.h>
#include <java.management.h>
#include <java.rmi.h>
#include <java.base.h>
#include <java.security.sasl.h>
#include <java.logging.h>
#include <java/lang/ClassEntry.h>
#include <java/lang/Library.h>
#include <java/lang/ModuleInfo.h>
#include <java/lang/ResourceEntry.h>
#include <jcpp.h>
#include <module-info>

#include <com/sun/jmx/remote/internal/rmi/ProxyRef.h>
#include <com/sun/jmx/remote/internal/rmi/RMIExporter.h>
#include <com/sun/jmx/remote/protocol/rmi/ClientProvider.h>
#include <com/sun/jmx/remote/protocol/rmi/ServerProvider.h>
#include <javax/management/remote/rmi/NoCallStackClassLoader.h>
#include <javax/management/remote/rmi/RMIConnection.h>
#include <javax/management/remote/rmi/RMIConnectionImpl.h>
#include <javax/management/remote/rmi/RMIConnectionImpl$1.h>
#include <javax/management/remote/rmi/RMIConnectionImpl$2.h>
#include <javax/management/remote/rmi/RMIConnectionImpl$3.h>
#include <javax/management/remote/rmi/RMIConnectionImpl$4.h>
#include <javax/management/remote/rmi/RMIConnectionImpl$5.h>
#include <javax/management/remote/rmi/RMIConnectionImpl$6.h>
#include <javax/management/remote/rmi/RMIConnectionImpl$7.h>
#include <javax/management/remote/rmi/RMIConnectionImpl$CombinedClassLoader.h>
#include <javax/management/remote/rmi/RMIConnectionImpl$CombinedClassLoader$ClassLoaderWrapper.h>
#include <javax/management/remote/rmi/RMIConnectionImpl$PrivilegedOperation.h>
#include <javax/management/remote/rmi/RMIConnectionImpl$RMIServerCommunicatorAdmin.h>
#include <javax/management/remote/rmi/RMIConnectionImpl$SetCcl.h>
#include <javax/management/remote/rmi/RMIConnectionImpl_Stub.h>
#include <javax/management/remote/rmi/RMIConnector.h>
#include <javax/management/remote/rmi/RMIConnector$1.h>
#include <javax/management/remote/rmi/RMIConnector$2.h>
#include <javax/management/remote/rmi/RMIConnector$3.h>
#include <javax/management/remote/rmi/RMIConnector$ObjectInputStreamWithLoader.h>
#include <javax/management/remote/rmi/RMIConnector$RMIClientCommunicatorAdmin.h>
#include <javax/management/remote/rmi/RMIConnector$RMINotifClient.h>
#include <javax/management/remote/rmi/RMIConnector$RemoteMBeanServerConnection.h>
#include <javax/management/remote/rmi/RMIConnector$Util.h>
#include <javax/management/remote/rmi/RMIConnectorServer.h>
#include <javax/management/remote/rmi/RMIIIOPServerImpl.h>
#include <javax/management/remote/rmi/RMIJRMPServerImpl.h>
#include <javax/management/remote/rmi/RMIServer.h>
#include <javax/management/remote/rmi/RMIServerImpl.h>
#include <javax/management/remote/rmi/RMIServerImpl_Stub.h>


#define $classEntry(name, clazz) {name, clazz::load$, $getMark(clazz)}
::java::lang::ClassEntry _java$management$rmi_classes_[] = {
	$classEntry("com.sun.jmx.remote.internal.rmi.ProxyRef", ::com::sun::jmx::remote::internal::rmi::ProxyRef),
	$classEntry("com.sun.jmx.remote.internal.rmi.RMIExporter", ::com::sun::jmx::remote::internal::rmi::RMIExporter),
	$classEntry("com.sun.jmx.remote.protocol.rmi.ClientProvider", ::com::sun::jmx::remote::protocol::rmi::ClientProvider),
	$classEntry("com.sun.jmx.remote.protocol.rmi.ServerProvider", ::com::sun::jmx::remote::protocol::rmi::ServerProvider),
	$classEntry("javax.management.remote.rmi.NoCallStackClassLoader", ::javax::management::remote::rmi::NoCallStackClassLoader),
	$classEntry("javax.management.remote.rmi.RMIConnection", ::javax::management::remote::rmi::RMIConnection),
	$classEntry("javax.management.remote.rmi.RMIConnectionImpl", ::javax::management::remote::rmi::RMIConnectionImpl),
	$classEntry("javax.management.remote.rmi.RMIConnectionImpl$1", ::javax::management::remote::rmi::RMIConnectionImpl$1),
	$classEntry("javax.management.remote.rmi.RMIConnectionImpl$2", ::javax::management::remote::rmi::RMIConnectionImpl$2),
	$classEntry("javax.management.remote.rmi.RMIConnectionImpl$3", ::javax::management::remote::rmi::RMIConnectionImpl$3),
	$classEntry("javax.management.remote.rmi.RMIConnectionImpl$4", ::javax::management::remote::rmi::RMIConnectionImpl$4),
	$classEntry("javax.management.remote.rmi.RMIConnectionImpl$5", ::javax::management::remote::rmi::RMIConnectionImpl$5),
	$classEntry("javax.management.remote.rmi.RMIConnectionImpl$6", ::javax::management::remote::rmi::RMIConnectionImpl$6),
	$classEntry("javax.management.remote.rmi.RMIConnectionImpl$7", ::javax::management::remote::rmi::RMIConnectionImpl$7),
	$classEntry("javax.management.remote.rmi.RMIConnectionImpl$CombinedClassLoader", ::javax::management::remote::rmi::RMIConnectionImpl$CombinedClassLoader),
	$classEntry("javax.management.remote.rmi.RMIConnectionImpl$CombinedClassLoader$ClassLoaderWrapper", ::javax::management::remote::rmi::RMIConnectionImpl$CombinedClassLoader$ClassLoaderWrapper),
	$classEntry("javax.management.remote.rmi.RMIConnectionImpl$PrivilegedOperation", ::javax::management::remote::rmi::RMIConnectionImpl$PrivilegedOperation),
	$classEntry("javax.management.remote.rmi.RMIConnectionImpl$RMIServerCommunicatorAdmin", ::javax::management::remote::rmi::RMIConnectionImpl$RMIServerCommunicatorAdmin),
	$classEntry("javax.management.remote.rmi.RMIConnectionImpl$SetCcl", ::javax::management::remote::rmi::RMIConnectionImpl$SetCcl),
	$classEntry("javax.management.remote.rmi.RMIConnectionImpl_Stub", ::javax::management::remote::rmi::RMIConnectionImpl_Stub),
	$classEntry("javax.management.remote.rmi.RMIConnector", ::javax::management::remote::rmi::RMIConnector),
	$classEntry("javax.management.remote.rmi.RMIConnector$1", ::javax::management::remote::rmi::RMIConnector$1),
	$classEntry("javax.management.remote.rmi.RMIConnector$2", ::javax::management::remote::rmi::RMIConnector$2),
	$classEntry("javax.management.remote.rmi.RMIConnector$3", ::javax::management::remote::rmi::RMIConnector$3),
	$classEntry("javax.management.remote.rmi.RMIConnector$ObjectInputStreamWithLoader", ::javax::management::remote::rmi::RMIConnector$ObjectInputStreamWithLoader),
	$classEntry("javax.management.remote.rmi.RMIConnector$RMIClientCommunicatorAdmin", ::javax::management::remote::rmi::RMIConnector$RMIClientCommunicatorAdmin),
	$classEntry("javax.management.remote.rmi.RMIConnector$RMINotifClient", ::javax::management::remote::rmi::RMIConnector$RMINotifClient),
	$classEntry("javax.management.remote.rmi.RMIConnector$RemoteMBeanServerConnection", ::javax::management::remote::rmi::RMIConnector$RemoteMBeanServerConnection),
	$classEntry("javax.management.remote.rmi.RMIConnector$Util", ::javax::management::remote::rmi::RMIConnector$Util),
	$classEntry("javax.management.remote.rmi.RMIConnectorServer", ::javax::management::remote::rmi::RMIConnectorServer),
	$classEntry("javax.management.remote.rmi.RMIIIOPServerImpl", ::javax::management::remote::rmi::RMIIIOPServerImpl),
	$classEntry("javax.management.remote.rmi.RMIJRMPServerImpl", ::javax::management::remote::rmi::RMIJRMPServerImpl),
	$classEntry("javax.management.remote.rmi.RMIServer", ::javax::management::remote::rmi::RMIServer),
	$classEntry("javax.management.remote.rmi.RMIServerImpl", ::javax::management::remote::rmi::RMIServerImpl),
	$classEntry("javax.management.remote.rmi.RMIServerImpl_Stub", ::javax::management::remote::rmi::RMIServerImpl_Stub)
};

const char* _java$management$rmi_packages_[] = {
	"com.sun.jmx.remote.internal.rmi",
	"com.sun.jmx.remote.protocol.rmi",
	"javax.management.remote.rmi"
};

void java$management$rmi$PreloadClass(void* eventData) {
	::java::lang::PreloadClassEvent* event = (::java::lang::PreloadClassEvent*)eventData;
	int32_t length = $lengthOf(_java$management$rmi_classes_);
	for (int i = 0; i < length; i++) {
		::java::lang::ClassEntry* classEntry = &_java$management$rmi_classes_[i];
		if (event->preinit) {
			if ($hasFlag(classEntry->mark, $PREINIT)) {
				classEntry->loader(nullptr, true);
				continue;
			}
		}
		if (event->preload) {
			if ($hasFlag(classEntry->mark, $PRELOAD) || $hasFlag(classEntry->mark, $PREINIT)) {
				classEntry->loader(nullptr, false);
			}
		}
	}
}

void java$management$rmi$LibEventAction(int32_t eventType, void* eventData) {
	if (eventType == JCPP_LIB_EVENT_TYPE_PRELOAD_CLASS) {
		java$management$rmi$PreloadClass(eventData);
	}
	if (eventType == JCPP_LIB_EVENT_TYPE_THREAD_START) {
		$onLibThreadStart(eventData);
	}
}

$StringArray* java$management$rmi$GetPackages() {
	int32_t length = $lengthOf(_java$management$rmi_packages_);
	$var($StringArray, packages, $new($StringArray, length));
	for (int32_t i = 0; i < length; i++) {
		packages->set(i, $str(_java$management$rmi_packages_[i]));
	}
	return packages;
}

::java::lang::ClassEntry* java$management$rmi$GetClassEntry($String* name) {
	int32_t begin = 0;
	int32_t end = $lengthOf(_java$management$rmi_classes_) - 1;
	while (begin <= end) {
		int32_t mid = begin + (end - begin) / 2;
		::java::lang::ClassEntry* classEntry = &_java$management$rmi_classes_[mid];
		int32_t ret = name->compareTo(classEntry->name);
		if (ret < 0) {
			end = mid - 1;
		} else if (ret > 0) {
			begin = mid + 1;
		} else {
			return classEntry;
		}
	}
	return nullptr;
}

$bytes* java$management$rmi$GetResource($String* name) {
	return nullptr;
}

void java$management$rmi::init() {
	::java$naming::init();
	::java$management::init();
	::java$rmi::init();
	::java$base::init();
	::java$security$sasl::init();
	::java$logging::init();
	::java::lang::Library lib = {
		"java.management.rmi", "17.35", "",
		&_java$management$rmi_ModuleInfo_,
		java$management$rmi$LibEventAction,
		java$management$rmi$GetPackages,
		java$management$rmi$GetClassEntry,
		java$management$rmi$GetResource
	};
	$System::addLibrary(&lib);
}