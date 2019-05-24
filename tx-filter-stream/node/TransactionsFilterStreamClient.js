const grpc = require('grpc');
const jsonToProtobufInterceptorFactory = require('./jsonToProtobufInterceptorFactory');
const loadPackageDefinition = require('./loadPackageDefinition');
const { TransactionsWithProofsResponse } = require('./tx_filter_stream_pb');
const isObject = require('./isObject');
const convertObjectToMetadata = require('./convertObjectToMetadata');

const {
  TransactionsFilterStream: TransactionsFilterStreamNodeJSClient,
} = loadPackageDefinition();

const subscribeToTransactionsWithProofsOptions = {
  interceptors: [jsonToProtobufInterceptorFactory(TransactionsWithProofsResponse)],
};

class TransactionsFilterStreamClient {
  /**
   * @param {string} hostname
   * @param {?Object} credentials
   * @param {?Object} options
   */
  constructor(hostname, credentials = grpc.credentials.createInsecure(), options = {}) {
    this.client = new TransactionsFilterStreamNodeJSClient(hostname, credentials, options);
  }

  /**
   * @param {TransactionsWithProofsRequest} transactionsWithProofsRequest The request proto
   * @param {?Object<string, string>} metadata User defined call metadata
   * @return {!grpc.web.ClientReadableStream<!TransactionsWithProofsResponse>|undefined}
   *     The XHR Node Readable Stream
   */
  subscribeToTransactionsWithProofs(transactionsWithProofsRequest, metadata = {}) {
    if (!isObject(metadata)) {
      throw new Error('metadata must be an object');
    }

    const message = transactionsWithProofsRequest.toObject();

    return this.client.subscribeToTransactionsWithProofs(
      message,
      convertObjectToMetadata(metadata),
      subscribeToTransactionsWithProofsOptions,
    );
  }
}

module.exports = TransactionsFilterStreamClient;
