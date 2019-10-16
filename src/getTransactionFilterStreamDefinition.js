const { loadPackageDefinition } = require('@dashevo/grpc-common');

function getTransactionFilterStreamDefinition() {
  const protoPath = '../protos/transactions_filter_stream.proto';

  return loadPackageDefinition(protoPath, 'org.dash.platform.dapi.v0.TransactionFilterStream');
}

module.exports = getTransactionFilterStreamDefinition;
