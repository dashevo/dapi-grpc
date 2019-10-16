const { loadPackageDefinition } = require('@dashevo/grpc-common');

function getCoreDefinition() {
  const protoPath = '../protos/core.proto';

  return loadPackageDefinition(protoPath, 'org.dash.platform.dapi.v0.Core');
}

module.exports = getCoreDefinition;
