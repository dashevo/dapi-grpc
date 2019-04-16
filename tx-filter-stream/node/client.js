const path = require('path');
const grpc = require('grpc');
const protoLoader = require('@grpc/proto-loader');
const messages = require('./tx_filter_stream_pb');

const protoPath = path.join(__dirname, '../tx_filter_stream.proto');

const definition = protoLoader.loadSync(protoPath, {
  keepCase: true,
  longs: String,
  enums: String,
  bytes: Array,
  defaults: true
});

const descriptor = grpc.loadPackageDefinition(definition);

const dapi = descriptor.org.dash.platform.dapi;
const client = new dapi.TransactionsFilterStream('http://127.0.0.1', grpc.credentials.createInsecure());

class TransactionsFilterStreamClient {
  constructor(hostname, credentials = grpc.credentials.createInsecure(), options = {}) {
    this.client = new dapi.TransactionsFilterStream(hostname, credentials, options);
  }

  GetNewTransactionsByFilter(message, metadata, callback) {
    const obj = message.toObject();
    this.client.GetNewTransactionsByFilter(obj, metadata, (err, response) => {
      if (typeof callback === 'function') {
        // TODO: need to wrap response for consistency:
        // node-client returns response.message, web client returns response.getMessage()
        callback(err, response);
      }
    });
  }
}

class TransactionsFilterStreamPromiseClient {
  constructor(hostname, credentials = grpc.credentials.createInsecure(), options = {}) {
    this.client = new dapi.TransactionsFilterStream(hostname, credentials, options);
  }

  GetNewTransactionsByFilter(message, metadata) {
    return new Promise((resolve, reject) => {
      const obj = message.toObject();
      this.client.GetNewTransactionsByFilter(obj, metadata, (err, response) => {
        if (err) {
          return reject(err);
        }
        // TODO: need to wrap response for consistency:
        // node-client returns response.message, web client returns response.getMessage()
        return resolve(response);
      });
    });
  }
}


module.exports = Object.assign( {
  TransactionsFilterStreamClient,
  TransactionsFilterStreamPromiseClient
}, messages);
