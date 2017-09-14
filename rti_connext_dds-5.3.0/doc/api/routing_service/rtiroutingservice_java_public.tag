<?xml version='1.0' encoding='UTF-8' standalone='yes' ?>
<tagfile>
  <compound kind="file">
    <name>RoutingService.java</name>
    <path>/home/build3/rti/waveworks/ndds530/connextdds/router.1.0/interface/com/rti/routingservice/</path>
    <filename>RoutingService_8java</filename>
    <class kind="class">com::rti::routingservice::RoutingService</class>
  </compound>
  <compound kind="file">
    <name>RoutingServiceProperty.java</name>
    <path>/home/build3/rti/waveworks/ndds530/connextdds/router.1.0/interface/com/rti/routingservice/</path>
    <filename>RoutingServiceProperty_8java</filename>
    <class kind="class">com::rti::routingservice::RoutingServiceProperty</class>
  </compound>
  <compound kind="group">
    <name>RTI_RoutingServiceLibModule</name>
    <title>RTI Routing Service API</title>
    <filename>group__RTI__RoutingServiceLibModule.html</filename>
    <class kind="class">com::rti::routingservice::RoutingService</class>
    <class kind="class">com::rti::routingservice::RoutingServiceProperty</class>
  </compound>
  <compound kind="group">
    <name>RTI_RoutingServiceAdapterModule</name>
    <title>RTI Routing Service Adapter API</title>
    <filename>group__RTI__RoutingServiceAdapterModule.html</filename>
    <class kind="interface">com::rti::routingservice::adapter::Adapter</class>
    <class kind="interface">com::rti::routingservice::adapter::Connection</class>
    <class kind="interface">com::rti::routingservice::adapter::DiscoveryConnection</class>
    <class kind="interface">com::rti::routingservice::adapter::Entity</class>
    <class kind="interface">com::rti::routingservice::adapter::Session</class>
    <class kind="interface">com::rti::routingservice::adapter::StreamReader</class>
    <class kind="interface">com::rti::routingservice::adapter::StreamReaderListener</class>
    <class kind="interface">com::rti::routingservice::adapter::StreamWriter</class>
    <docanchor file="group__RTI__RoutingServiceAdapterModule">Requirements</docanchor>
  </compound>
  <compound kind="group">
    <name>ROUTER</name>
    <title>RTI Routing Service</title>
    <filename>group__ROUTER.html</filename>
    <subgroup>RTI_RoutingServiceLibModule</subgroup>
    <subgroup>RTI_RoutingServiceAdapterModule</subgroup>
    <subgroup>RTI_RoutingServiceInfrastructureModule</subgroup>
  </compound>
  <compound kind="group">
    <name>RTI_RoutingServiceInfrastructureModule</name>
    <title>RTI Routing Service Infrastructure</title>
    <filename>group__RTI__RoutingServiceInfrastructureModule.html</filename>
    <subgroup>RTI_RoutingServiceTypeRepresentationModule</subgroup>
    <subgroup>RTI_RoutingServiceDataRepresentationModule</subgroup>
    <class kind="class">com::rti::routingservice::adapter::infrastructure::AdapterException</class>
    <class kind="class">com::rti::routingservice::adapter::infrastructure::StreamInfo</class>
    <class kind="class">com::rti::routingservice::adapter::infrastructure::TypeInfo</class>
    <class kind="class">com::rti::routingservice::adapter::infrastructure::Version</class>
    <class kind="class">com::rti::routingservice::infrastructure::OutOfResourcesException</class>
    <class kind="class">com::rti::routingservice::infrastructure::RoutingServiceException</class>
  </compound>
  <compound kind="group">
    <name>RTI_RoutingServiceTypeRepresentationModule</name>
    <title>Standard Type Representation Kinds</title>
    <filename>group__RTI__RoutingServiceTypeRepresentationModule.html</filename>
    <member kind="variable" static="yes">
      <type>static int</type>
      <name>DYNAMIC_TYPE_REPRESENTATION</name>
      <anchorfile>group__RTI__RoutingServiceTypeRepresentationModule.html</anchorfile>
      <anchor>ga5f9505fa9c6ca3360f0dc634f065c139</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static int</type>
      <name>XML_TYPE_REPRESENTATION</name>
      <anchorfile>group__RTI__RoutingServiceTypeRepresentationModule.html</anchorfile>
      <anchor>gae2ffbdd7a733ac16288bfe3c30c75685</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static int</type>
      <name>JAVA_OBJECT_TYPE_REPRESENTATION</name>
      <anchorfile>group__RTI__RoutingServiceTypeRepresentationModule.html</anchorfile>
      <anchor>ga9f17c2e16502e92e1015d314f84230c3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>RTI_RoutingServiceDataRepresentationModule</name>
    <title>Standard Data Representation Kinds</title>
    <filename>group__RTI__RoutingServiceDataRepresentationModule.html</filename>
    <member kind="variable" static="yes">
      <type>static int</type>
      <name>DYNAMIC_DATA_REPRESENTATION</name>
      <anchorfile>group__RTI__RoutingServiceDataRepresentationModule.html</anchorfile>
      <anchor>ga4d20e3766106f72fc841c411883c4e55</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static int</type>
      <name>XML_DATA_REPRESENTATION</name>
      <anchorfile>group__RTI__RoutingServiceDataRepresentationModule.html</anchorfile>
      <anchor>gaf2a80206680a2c61a36d9b0ede904969</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static int</type>
      <name>JAVA_OBJECT_DATA_REPRESENTATION</name>
      <anchorfile>group__RTI__RoutingServiceDataRepresentationModule.html</anchorfile>
      <anchor>ga09ffb5d28c844144ee4ac1b314b54b8d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>com::rti::routingservice::RoutingService</name>
    <filename>classcom_1_1rti_1_1routingservice_1_1RoutingService.html</filename>
    <member kind="function">
      <type></type>
      <name>RoutingService</name>
      <anchorfile>classcom_1_1rti_1_1routingservice_1_1RoutingService.html</anchorfile>
      <anchor>a6e916aa47335ae990f24afa16bf2c8ba</anchor>
      <arglist>(RoutingServiceProperty property)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>close</name>
      <anchorfile>classcom_1_1rti_1_1routingservice_1_1RoutingService.html</anchorfile>
      <anchor>a5ae591df94fc66ccb85cbb6565368bca</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>start</name>
      <anchorfile>classcom_1_1rti_1_1routingservice_1_1RoutingService.html</anchorfile>
      <anchor>a60de64d75454385b23995437f1d72669</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>stop</name>
      <anchorfile>classcom_1_1rti_1_1routingservice_1_1RoutingService.html</anchorfile>
      <anchor>a8c528baf37154d347366083f0f816846</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>createEntity</name>
      <anchorfile>classcom_1_1rti_1_1routingservice_1_1RoutingService.html</anchorfile>
      <anchor>a49c053a27b9ea03a81147300d789cc69</anchor>
      <arglist>(String parentName, String xmlSnippet)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteEntity</name>
      <anchorfile>classcom_1_1rti_1_1routingservice_1_1RoutingService.html</anchorfile>
      <anchor>a93276bda3b33f0fb4f11408e22d0a96c</anchor>
      <arglist>(String entityName)</arglist>
    </member>
    <member kind="function">
      <type>String</type>
      <name>getConfiguration</name>
      <anchorfile>classcom_1_1rti_1_1routingservice_1_1RoutingService.html</anchorfile>
      <anchor>ab1d26db3309a44d4527c98900c829e79</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static final int</type>
      <name>LOG_VERBOSITY_SILENT</name>
      <anchorfile>classcom_1_1rti_1_1routingservice_1_1RoutingService.html</anchorfile>
      <anchor>a83a2f38f912bfe8067a28f72e40661a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static final int</type>
      <name>LOG_VERBOSITY_EXCEPTIONS</name>
      <anchorfile>classcom_1_1rti_1_1routingservice_1_1RoutingService.html</anchorfile>
      <anchor>a598e84b0bfe171eb788b7c761c8ef737</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static final int</type>
      <name>LOG_VERBOSITY_WARNINGS</name>
      <anchorfile>classcom_1_1rti_1_1routingservice_1_1RoutingService.html</anchorfile>
      <anchor>a92e4a14aeeedfcd4b6c5cf70f3d05400</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static final int</type>
      <name>LOG_VERBOSITY_INFO</name>
      <anchorfile>classcom_1_1rti_1_1routingservice_1_1RoutingService.html</anchorfile>
      <anchor>a70f21e5b7b46cf6982d6de1bdab44bfc</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>com::rti::routingservice::RoutingServiceProperty</name>
    <filename>classcom_1_1rti_1_1routingservice_1_1RoutingServiceProperty.html</filename>
    <member kind="function">
      <type></type>
      <name>RoutingServiceProperty</name>
      <anchorfile>classcom_1_1rti_1_1routingservice_1_1RoutingServiceProperty.html</anchorfile>
      <anchor>a87da12460d66dd65c065cbfc08af4feb</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable">
      <type>String</type>
      <name>cfgFile</name>
      <anchorfile>classcom_1_1rti_1_1routingservice_1_1RoutingServiceProperty.html</anchorfile>
      <anchor>a6563c48993443ee07401877f64fd618f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>String[]</type>
      <name>cfgStrings</name>
      <anchorfile>classcom_1_1rti_1_1routingservice_1_1RoutingServiceProperty.html</anchorfile>
      <anchor>aa5dc531161ef1fd76a6e7d2b43037278</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>String</type>
      <name>serviceName</name>
      <anchorfile>classcom_1_1rti_1_1routingservice_1_1RoutingServiceProperty.html</anchorfile>
      <anchor>a0e55f18fcc71234334c1b9d4221e1e3e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>String</type>
      <name>applicationName</name>
      <anchorfile>classcom_1_1rti_1_1routingservice_1_1RoutingServiceProperty.html</anchorfile>
      <anchor>a995737d2d7b215cb955c510c32104bab</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>serviceVerbosity</name>
      <anchorfile>classcom_1_1rti_1_1routingservice_1_1RoutingServiceProperty.html</anchorfile>
      <anchor>a9df41336102579fd4220c49dc7647cd6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>ddsVerbosity</name>
      <anchorfile>classcom_1_1rti_1_1routingservice_1_1RoutingServiceProperty.html</anchorfile>
      <anchor>a9f2197d519060d05c088f21917a32773</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>domainIdBase</name>
      <anchorfile>classcom_1_1rti_1_1routingservice_1_1RoutingServiceProperty.html</anchorfile>
      <anchor>a9c39281923d9c497923b60dbadacfda9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>String</type>
      <name>transformationSearchPath</name>
      <anchorfile>classcom_1_1rti_1_1routingservice_1_1RoutingServiceProperty.html</anchorfile>
      <anchor>aba6045caeaa661efaf439079ae147eaa</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>boolean</type>
      <name>dontStartService</name>
      <anchorfile>classcom_1_1rti_1_1routingservice_1_1RoutingServiceProperty.html</anchorfile>
      <anchor>abb2bc06b4f8cb43f8a60b56e7fa9d349</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>boolean</type>
      <name>enableAdministration</name>
      <anchorfile>classcom_1_1rti_1_1routingservice_1_1RoutingServiceProperty.html</anchorfile>
      <anchor>a54672a484551013cdf8478b60d786981</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>administrationDomainId</name>
      <anchorfile>classcom_1_1rti_1_1routingservice_1_1RoutingServiceProperty.html</anchorfile>
      <anchor>a16bc157f4f6a262b81856b1826dd7cd7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>boolean</type>
      <name>enableMonitoring</name>
      <anchorfile>classcom_1_1rti_1_1routingservice_1_1RoutingServiceProperty.html</anchorfile>
      <anchor>a75c6e45c11f07470862657a801004318</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>monitoringDomainId</name>
      <anchorfile>classcom_1_1rti_1_1routingservice_1_1RoutingServiceProperty.html</anchorfile>
      <anchor>a71b408ee93210d81a9dd7f512f54d78a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>boolean</type>
      <name>skipDefaultFiles</name>
      <anchorfile>classcom_1_1rti_1_1routingservice_1_1RoutingServiceProperty.html</anchorfile>
      <anchor>a6a91efa301ab37083df866760d5dcf98</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>boolean</type>
      <name>identifyExecution</name>
      <anchorfile>classcom_1_1rti_1_1routingservice_1_1RoutingServiceProperty.html</anchorfile>
      <anchor>ae7035b07c1fc8406e198f6581c6c0380</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>boolean</type>
      <name>use42eAlignment</name>
      <anchorfile>classcom_1_1rti_1_1routingservice_1_1RoutingServiceProperty.html</anchorfile>
      <anchor>a5fda671521b1bbb8b770c5874d0c1da8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>String</type>
      <name>licenseFileName</name>
      <anchorfile>classcom_1_1rti_1_1routingservice_1_1RoutingServiceProperty.html</anchorfile>
      <anchor>a38bf50d150b09cacfefc1e1a6c64085b</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="interface">
    <name>com::rti::routingservice::adapter::Adapter</name>
    <filename>interfacecom_1_1rti_1_1routingservice_1_1adapter_1_1Adapter.html</filename>
    <member kind="function">
      <type>Connection</type>
      <name>createConnection</name>
      <anchorfile>interfacecom_1_1rti_1_1routingservice_1_1adapter_1_1Adapter.html</anchorfile>
      <anchor>a4106997121e055c6ca897cb886efbfb2</anchor>
      <arglist>(String routingServiceName, String routingServiceGroupName, StreamReaderListener inputStreamDiscoveryListener, StreamReaderListener outputStreamDiscoveryListener, Properties properties)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteConnection</name>
      <anchorfile>interfacecom_1_1rti_1_1routingservice_1_1adapter_1_1Adapter.html</anchorfile>
      <anchor>a6cc0ec7bc4977fb66128e183ec64eeb6</anchor>
      <arglist>(Connection connection)</arglist>
    </member>
    <member kind="function">
      <type>Version</type>
      <name>getVersion</name>
      <anchorfile>interfacecom_1_1rti_1_1routingservice_1_1adapter_1_1Adapter.html</anchorfile>
      <anchor>aa5ccfffc84430dcb3abf4d2b624ee440</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="interface">
    <name>com::rti::routingservice::adapter::Connection</name>
    <filename>interfacecom_1_1rti_1_1routingservice_1_1adapter_1_1Connection.html</filename>
    <base>com::rti::routingservice::adapter::Entity</base>
    <member kind="function">
      <type>Session</type>
      <name>createSession</name>
      <anchorfile>interfacecom_1_1rti_1_1routingservice_1_1adapter_1_1Connection.html</anchorfile>
      <anchor>af08a261a25e4a029f22d2ce6d3603799</anchor>
      <arglist>(Properties properties)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteSession</name>
      <anchorfile>interfacecom_1_1rti_1_1routingservice_1_1adapter_1_1Connection.html</anchorfile>
      <anchor>a25c3ac74111cb9dba324e5e3aa6f270f</anchor>
      <arglist>(Session session)</arglist>
    </member>
    <member kind="function">
      <type>StreamReader</type>
      <name>createStreamReader</name>
      <anchorfile>interfacecom_1_1rti_1_1routingservice_1_1adapter_1_1Connection.html</anchorfile>
      <anchor>ab256d93036b18be2b150aaea41beee44</anchor>
      <arglist>(Session session, StreamInfo streamInfo, Properties properties, StreamReaderListener listener)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteStreamReader</name>
      <anchorfile>interfacecom_1_1rti_1_1routingservice_1_1adapter_1_1Connection.html</anchorfile>
      <anchor>a416e42b4faf03d5c06114fc072a4efab</anchor>
      <arglist>(StreamReader streamReader)</arglist>
    </member>
    <member kind="function">
      <type>StreamWriter</type>
      <name>createStreamWriter</name>
      <anchorfile>interfacecom_1_1rti_1_1routingservice_1_1adapter_1_1Connection.html</anchorfile>
      <anchor>af3b5d99539c101a43773bcb74cd3ccb8</anchor>
      <arglist>(Session session, StreamInfo streamInfo, Properties properties)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteStreamWriter</name>
      <anchorfile>interfacecom_1_1rti_1_1routingservice_1_1adapter_1_1Connection.html</anchorfile>
      <anchor>a5cdcfafcee23c1c67f0d98341a165b9e</anchor>
      <arglist>(StreamWriter streamWriter)</arglist>
    </member>
    <member kind="function">
      <type>Properties</type>
      <name>getAttributes</name>
      <anchorfile>interfacecom_1_1rti_1_1routingservice_1_1adapter_1_1Connection.html</anchorfile>
      <anchor>ad27466f949b48fc29cba8e419ec1d640</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>update</name>
      <anchorfile>interfacecom_1_1rti_1_1routingservice_1_1adapter_1_1Entity.html</anchorfile>
      <anchor>a7462535fc9b26632625c7dab38804947</anchor>
      <arglist>(Properties properties)</arglist>
    </member>
  </compound>
  <compound kind="interface">
    <name>com::rti::routingservice::adapter::DiscoveryConnection</name>
    <filename>interfacecom_1_1rti_1_1routingservice_1_1adapter_1_1DiscoveryConnection.html</filename>
    <base>com::rti::routingservice::adapter::Connection</base>
    <member kind="function">
      <type>StreamReader</type>
      <name>getInputStreamDiscoveryReader</name>
      <anchorfile>interfacecom_1_1rti_1_1routingservice_1_1adapter_1_1DiscoveryConnection.html</anchorfile>
      <anchor>a182278d97169de0f6ad1829dd5a577b1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>StreamReader</type>
      <name>getOutputStreamDiscoveryReader</name>
      <anchorfile>interfacecom_1_1rti_1_1routingservice_1_1adapter_1_1DiscoveryConnection.html</anchorfile>
      <anchor>a71768a35ce0be2a9fdbfa048234f0872</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>Object</type>
      <name>copyTypeRepresentation</name>
      <anchorfile>interfacecom_1_1rti_1_1routingservice_1_1adapter_1_1DiscoveryConnection.html</anchorfile>
      <anchor>ac9b10fbe36c6f0d6d68afe948e26c2bd</anchor>
      <arglist>(Object typeRepresentation)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteTypeRepresentation</name>
      <anchorfile>interfacecom_1_1rti_1_1routingservice_1_1adapter_1_1DiscoveryConnection.html</anchorfile>
      <anchor>a03b5a07dc14857794b88549ab428b964</anchor>
      <arglist>(Object typeRepresentation)</arglist>
    </member>
    <member kind="function">
      <type>Session</type>
      <name>createSession</name>
      <anchorfile>interfacecom_1_1rti_1_1routingservice_1_1adapter_1_1Connection.html</anchorfile>
      <anchor>af08a261a25e4a029f22d2ce6d3603799</anchor>
      <arglist>(Properties properties)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteSession</name>
      <anchorfile>interfacecom_1_1rti_1_1routingservice_1_1adapter_1_1Connection.html</anchorfile>
      <anchor>a25c3ac74111cb9dba324e5e3aa6f270f</anchor>
      <arglist>(Session session)</arglist>
    </member>
    <member kind="function">
      <type>StreamReader</type>
      <name>createStreamReader</name>
      <anchorfile>interfacecom_1_1rti_1_1routingservice_1_1adapter_1_1Connection.html</anchorfile>
      <anchor>ab256d93036b18be2b150aaea41beee44</anchor>
      <arglist>(Session session, StreamInfo streamInfo, Properties properties, StreamReaderListener listener)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteStreamReader</name>
      <anchorfile>interfacecom_1_1rti_1_1routingservice_1_1adapter_1_1Connection.html</anchorfile>
      <anchor>a416e42b4faf03d5c06114fc072a4efab</anchor>
      <arglist>(StreamReader streamReader)</arglist>
    </member>
    <member kind="function">
      <type>StreamWriter</type>
      <name>createStreamWriter</name>
      <anchorfile>interfacecom_1_1rti_1_1routingservice_1_1adapter_1_1Connection.html</anchorfile>
      <anchor>af3b5d99539c101a43773bcb74cd3ccb8</anchor>
      <arglist>(Session session, StreamInfo streamInfo, Properties properties)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteStreamWriter</name>
      <anchorfile>interfacecom_1_1rti_1_1routingservice_1_1adapter_1_1Connection.html</anchorfile>
      <anchor>a5cdcfafcee23c1c67f0d98341a165b9e</anchor>
      <arglist>(StreamWriter streamWriter)</arglist>
    </member>
    <member kind="function">
      <type>Properties</type>
      <name>getAttributes</name>
      <anchorfile>interfacecom_1_1rti_1_1routingservice_1_1adapter_1_1Connection.html</anchorfile>
      <anchor>ad27466f949b48fc29cba8e419ec1d640</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>update</name>
      <anchorfile>interfacecom_1_1rti_1_1routingservice_1_1adapter_1_1Entity.html</anchorfile>
      <anchor>a7462535fc9b26632625c7dab38804947</anchor>
      <arglist>(Properties properties)</arglist>
    </member>
  </compound>
  <compound kind="interface">
    <name>com::rti::routingservice::adapter::Entity</name>
    <filename>interfacecom_1_1rti_1_1routingservice_1_1adapter_1_1Entity.html</filename>
    <member kind="function">
      <type>void</type>
      <name>update</name>
      <anchorfile>interfacecom_1_1rti_1_1routingservice_1_1adapter_1_1Entity.html</anchorfile>
      <anchor>a7462535fc9b26632625c7dab38804947</anchor>
      <arglist>(Properties properties)</arglist>
    </member>
  </compound>
  <compound kind="interface">
    <name>com::rti::routingservice::adapter::Session</name>
    <filename>interfacecom_1_1rti_1_1routingservice_1_1adapter_1_1Session.html</filename>
    <base>com::rti::routingservice::adapter::Entity</base>
    <member kind="function">
      <type>void</type>
      <name>update</name>
      <anchorfile>interfacecom_1_1rti_1_1routingservice_1_1adapter_1_1Entity.html</anchorfile>
      <anchor>a7462535fc9b26632625c7dab38804947</anchor>
      <arglist>(Properties properties)</arglist>
    </member>
  </compound>
  <compound kind="interface">
    <name>com::rti::routingservice::adapter::StreamReader</name>
    <filename>interfacecom_1_1rti_1_1routingservice_1_1adapter_1_1StreamReader.html</filename>
    <base>com::rti::routingservice::adapter::Entity</base>
    <member kind="function">
      <type>void</type>
      <name>read</name>
      <anchorfile>interfacecom_1_1rti_1_1routingservice_1_1adapter_1_1StreamReader.html</anchorfile>
      <anchor>a01378814091fb13b56c880bffbc8831b</anchor>
      <arglist>(List&lt; Object &gt; sampleList, List&lt; Object &gt; infoList)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>returnLoan</name>
      <anchorfile>interfacecom_1_1rti_1_1routingservice_1_1adapter_1_1StreamReader.html</anchorfile>
      <anchor>a5fe0e65554a5c6fd065094dd37927905</anchor>
      <arglist>(List&lt; Object &gt; sampleList, List&lt; Object &gt; infoList)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>update</name>
      <anchorfile>interfacecom_1_1rti_1_1routingservice_1_1adapter_1_1Entity.html</anchorfile>
      <anchor>a7462535fc9b26632625c7dab38804947</anchor>
      <arglist>(Properties properties)</arglist>
    </member>
  </compound>
  <compound kind="interface">
    <name>com::rti::routingservice::adapter::StreamReaderListener</name>
    <filename>interfacecom_1_1rti_1_1routingservice_1_1adapter_1_1StreamReaderListener.html</filename>
    <member kind="function">
      <type>void</type>
      <name>onDataAvailable</name>
      <anchorfile>interfacecom_1_1rti_1_1routingservice_1_1adapter_1_1StreamReaderListener.html</anchorfile>
      <anchor>acabe5436cf08557f1d76eb22926cdd2e</anchor>
      <arglist>(StreamReader streamReader)</arglist>
    </member>
  </compound>
  <compound kind="interface">
    <name>com::rti::routingservice::adapter::StreamWriter</name>
    <filename>interfacecom_1_1rti_1_1routingservice_1_1adapter_1_1StreamWriter.html</filename>
    <base>com::rti::routingservice::adapter::Entity</base>
    <member kind="function">
      <type>int</type>
      <name>write</name>
      <anchorfile>interfacecom_1_1rti_1_1routingservice_1_1adapter_1_1StreamWriter.html</anchorfile>
      <anchor>a3dc6ba6213852599430936cae8f51787</anchor>
      <arglist>(List&lt; Object &gt; sampleList, List&lt; Object &gt; infoList)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>update</name>
      <anchorfile>interfacecom_1_1rti_1_1routingservice_1_1adapter_1_1Entity.html</anchorfile>
      <anchor>a7462535fc9b26632625c7dab38804947</anchor>
      <arglist>(Properties properties)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>com::rti::routingservice::adapter::infrastructure::AdapterException</name>
    <filename>classcom_1_1rti_1_1routingservice_1_1adapter_1_1infrastructure_1_1AdapterException.html</filename>
    <member kind="function">
      <type></type>
      <name>AdapterException</name>
      <anchorfile>classcom_1_1rti_1_1routingservice_1_1adapter_1_1infrastructure_1_1AdapterException.html</anchorfile>
      <anchor>a4c54a8bb5ed61c88315100886045bda3</anchor>
      <arglist>(int nativeCode, String message)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>AdapterException</name>
      <anchorfile>classcom_1_1rti_1_1routingservice_1_1adapter_1_1infrastructure_1_1AdapterException.html</anchorfile>
      <anchor>a91717bec2df6c06d8788ac84cade67a6</anchor>
      <arglist>(int nativeCode, String message, Throwable cause)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>AdapterException</name>
      <anchorfile>classcom_1_1rti_1_1routingservice_1_1adapter_1_1infrastructure_1_1AdapterException.html</anchorfile>
      <anchor>a219a62e477dbd5abb34e9b452037d5ad</anchor>
      <arglist>(int nativeCode, Throwable cause)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getNativeCode</name>
      <anchorfile>classcom_1_1rti_1_1routingservice_1_1adapter_1_1infrastructure_1_1AdapterException.html</anchorfile>
      <anchor>a10c2bf11e4aee866022ce7af90ca59f0</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>com::rti::routingservice::adapter::infrastructure::StreamInfo</name>
    <filename>classcom_1_1rti_1_1routingservice_1_1adapter_1_1infrastructure_1_1StreamInfo.html</filename>
    <member kind="function">
      <type>String</type>
      <name>getStreamName</name>
      <anchorfile>classcom_1_1rti_1_1routingservice_1_1adapter_1_1infrastructure_1_1StreamInfo.html</anchorfile>
      <anchor>a86a2c4501713436901b2a30dfe7514e0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>TypeInfo</type>
      <name>getTypeInfo</name>
      <anchorfile>classcom_1_1rti_1_1routingservice_1_1adapter_1_1infrastructure_1_1StreamInfo.html</anchorfile>
      <anchor>ac1af09a890b1dc5e7a645ba05401bcab</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>boolean</type>
      <name>isDisposed</name>
      <anchorfile>classcom_1_1rti_1_1routingservice_1_1adapter_1_1infrastructure_1_1StreamInfo.html</anchorfile>
      <anchor>aa9cdeaede4092664454988f66ca4495f</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>com::rti::routingservice::adapter::infrastructure::TypeInfo</name>
    <filename>classcom_1_1rti_1_1routingservice_1_1adapter_1_1infrastructure_1_1TypeInfo.html</filename>
    <member kind="function">
      <type></type>
      <name>TypeInfo</name>
      <anchorfile>classcom_1_1rti_1_1routingservice_1_1adapter_1_1infrastructure_1_1TypeInfo.html</anchorfile>
      <anchor>ae68820abdd8fb41253d08bbf380f2473</anchor>
      <arglist>(String typeName, Object typeRepresentation)</arglist>
    </member>
    <member kind="function">
      <type>String</type>
      <name>getTypeName</name>
      <anchorfile>classcom_1_1rti_1_1routingservice_1_1adapter_1_1infrastructure_1_1TypeInfo.html</anchorfile>
      <anchor>a9f0f20d4149a5730b858d8faff891de4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>Object</type>
      <name>getTypeRepresentation</name>
      <anchorfile>classcom_1_1rti_1_1routingservice_1_1adapter_1_1infrastructure_1_1TypeInfo.html</anchorfile>
      <anchor>a0b9e520c986479c3e028b2f9fbdcd299</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static int</type>
      <name>DYNAMIC_TYPE_REPRESENTATION</name>
      <anchorfile>group__RTI__RoutingServiceTypeRepresentationModule.html</anchorfile>
      <anchor>ga5f9505fa9c6ca3360f0dc634f065c139</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static int</type>
      <name>XML_TYPE_REPRESENTATION</name>
      <anchorfile>group__RTI__RoutingServiceTypeRepresentationModule.html</anchorfile>
      <anchor>gae2ffbdd7a733ac16288bfe3c30c75685</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static int</type>
      <name>JAVA_OBJECT_TYPE_REPRESENTATION</name>
      <anchorfile>group__RTI__RoutingServiceTypeRepresentationModule.html</anchorfile>
      <anchor>ga9f17c2e16502e92e1015d314f84230c3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static int</type>
      <name>DYNAMIC_DATA_REPRESENTATION</name>
      <anchorfile>group__RTI__RoutingServiceDataRepresentationModule.html</anchorfile>
      <anchor>ga4d20e3766106f72fc841c411883c4e55</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static int</type>
      <name>XML_DATA_REPRESENTATION</name>
      <anchorfile>group__RTI__RoutingServiceDataRepresentationModule.html</anchorfile>
      <anchor>gaf2a80206680a2c61a36d9b0ede904969</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static int</type>
      <name>JAVA_OBJECT_DATA_REPRESENTATION</name>
      <anchorfile>group__RTI__RoutingServiceDataRepresentationModule.html</anchorfile>
      <anchor>ga09ffb5d28c844144ee4ac1b314b54b8d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>com::rti::routingservice::adapter::infrastructure::Version</name>
    <filename>classcom_1_1rti_1_1routingservice_1_1adapter_1_1infrastructure_1_1Version.html</filename>
    <member kind="function">
      <type></type>
      <name>Version</name>
      <anchorfile>classcom_1_1rti_1_1routingservice_1_1adapter_1_1infrastructure_1_1Version.html</anchorfile>
      <anchor>a4bbec7250187a8c6dd2e9e51828b103c</anchor>
      <arglist>(int major, int minor, int release, int revision)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>com::rti::routingservice::infrastructure::OutOfResourcesException</name>
    <filename>classcom_1_1rti_1_1routingservice_1_1infrastructure_1_1OutOfResourcesException.html</filename>
    <base>com::rti::routingservice::infrastructure::RoutingServiceException</base>
  </compound>
  <compound kind="class">
    <name>com::rti::routingservice::infrastructure::RoutingServiceException</name>
    <filename>classcom_1_1rti_1_1routingservice_1_1infrastructure_1_1RoutingServiceException.html</filename>
  </compound>
  <compound kind="dir">
    <name>adapter</name>
    <path>/home/build3/rti/waveworks/ndds530/connextdds/router.1.0/interface/com/rti/routingservice/adapter/</path>
    <filename>dir_548f7baeda1dbab57ff8f77a481d5577.html</filename>
    <dir>infrastructure</dir>
    <file>Adapter.java</file>
    <file>Connection.java</file>
    <file>DiscoveryConnection.java</file>
    <file>Entity.java</file>
    <file>Session.java</file>
    <file>StreamReader.java</file>
    <file>StreamReaderListener.java</file>
    <file>StreamWriter.java</file>
  </compound>
  <compound kind="dir">
    <name>com</name>
    <path>/home/build3/rti/waveworks/ndds530/connextdds/router.1.0/interface/com/</path>
    <filename>dir_ccd98340c540bf58e0cbf1b2395255e7.html</filename>
    <dir>rti</dir>
  </compound>
  <compound kind="dir">
    <name>infrastructure</name>
    <path>/home/build3/rti/waveworks/ndds530/connextdds/router.1.0/interface/com/rti/routingservice/infrastructure/</path>
    <filename>dir_bf47589a5cbccd3b923c177c6529eda1.html</filename>
    <file>OutOfResourcesException.java</file>
    <file>RoutingServiceException.java</file>
  </compound>
  <compound kind="dir">
    <name>infrastructure</name>
    <path>/home/build3/rti/waveworks/ndds530/connextdds/router.1.0/interface/com/rti/routingservice/adapter/infrastructure/</path>
    <filename>dir_7590b3915f16663237823b31fc6aa510.html</filename>
    <file>AdapterException.java</file>
    <file>StreamInfo.java</file>
    <file>TypeInfo.java</file>
    <file>Version.java</file>
  </compound>
  <compound kind="dir">
    <name>interface</name>
    <path>/home/build3/rti/waveworks/ndds530/connextdds/router.1.0/interface/</path>
    <filename>dir_5ef81cfdb3ba9f28353739905883c18a.html</filename>
    <dir>com</dir>
  </compound>
  <compound kind="dir">
    <name>routingservice</name>
    <path>/home/build3/rti/waveworks/ndds530/connextdds/router.1.0/interface/com/rti/routingservice/</path>
    <filename>dir_b79dfe8b16e0b56430f2fd923d3d660b.html</filename>
    <dir>adapter</dir>
    <dir>infrastructure</dir>
    <file>RoutingService.java</file>
    <file>RoutingServiceProperty.java</file>
  </compound>
  <compound kind="dir">
    <name>rti</name>
    <path>/home/build3/rti/waveworks/ndds530/connextdds/router.1.0/interface/com/rti/</path>
    <filename>dir_289510e0faefd54b248cdee86350707f.html</filename>
    <dir>routingservice</dir>
  </compound>
  <compound kind="dir">
    <name>srcDoc</name>
    <path>/home/build3/rti/waveworks/ndds530/connextdds/router.1.0/srcDoc/</path>
    <filename>dir_ade86ca28bbf812ecffad74b9289cba9.html</filename>
    <file>adapter.dxx</file>
    <file>main.dxx</file>
  </compound>
  <compound kind="page">
    <name>index</name>
    <title></title>
    <filename>index</filename>
    <docanchor file="index">main_support</docanchor>
  </compound>
</tagfile>
