const grpc = require('grpc');
const { promisify } = require('util');

const {
  convertObjectToMetadata,
  utils: {
    isObject,
  },
  client: {
    interceptors: {
      jsonToProtobufInterceptorFactory,
    },
    converters: {
      jsonToProtobufFactory,
      protobufToJsonFactory,
    },
  },
} = require('@dashevo/grpc-common');

const {
  org: {
    dash: {
      platform: {
        dapi: {
          v0: {
            SendTransactionRequest: PBJSSendTransactionRequest,
            SendTransactionResponse: PBJSSendTransactionResponse,
            GetBestBlockHeightRequest: PBJSGetBestBlockHeightRequest,
            GetBestBlockHeightResponse: PBJSGetBestBlockHeightResponse,
            GetTransactionRequest: PBJSGetTransactionRequest,
            GetTransactionResponse: PBJSGetTransactionResponse,
          },
        },
      },
    },
  },
} = require('./core_pbjs');

const {
  SendTransactionResponse: ProtocSendTransactionResponse,
  GetBestBlockHeightResponse: ProtocGetBestBlockHeightResponse,
  GetTransactionResponse: ProtocGetTransactionResponse,
} = require('./core_protoc');

const getCoreDefinition = require('../../lib/getCoreDefinition');

const CoreNodeJSClient = getCoreDefinition();

const sendTransactionOptions = {
  interceptors: [
    jsonToProtobufInterceptorFactory(
      jsonToProtobufFactory(
        ProtocSendTransactionResponse,
        PBJSSendTransactionResponse,
      ),
      protobufToJsonFactory(
        PBJSSendTransactionRequest,
      ),
    ),
  ],
};

const getBestBlockHeightOptions = {
  interceptors: [
    jsonToProtobufInterceptorFactory(
      jsonToProtobufFactory(
        ProtocGetBestBlockHeightResponse,
        PBJSGetBestBlockHeightResponse,
      ),
      protobufToJsonFactory(
        PBJSGetBestBlockHeightRequest,
      ),
    ),
  ],
};

const getTransactionOptions = {
  interceptors: [
    jsonToProtobufInterceptorFactory(
      jsonToProtobufFactory(
        ProtocGetTransactionResponse,
        PBJSGetTransactionResponse,
      ),
      protobufToJsonFactory(
        PBJSGetTransactionRequest,
      ),
    ),
  ],
};

class CorePromiseClient {
  /**
   * @param {string} hostname
   * @param {?Object} credentials
   * @param {?Object} options
   */
  constructor(hostname, credentials = grpc.credentials.createInsecure(), options = {}) {
    this.client = new CoreNodeJSClient(hostname, credentials, options);

    this.client.sendTransaction = promisify(
      this.client.sendTransaction.bind(this.client),
    );

    this.client.getTransaction = promisify(
      this.client.getTransaction.bind(this.client),
    );

    this.client.getBestBlockHeight = promisify(
      this.client.getBestBlockHeight.bind(this.client),
    );
  }

  /**
   * @param {!SendTransactionRequest} sendTransactionRequest
   * @param {?Object<string, string>} metadata
   * @return {Promise<!SendTransactionResponse>}
   */
  sendTransaction(sendTransactionRequest, metadata = {}) {
    if (!isObject(metadata)) {
      throw new Error('metadata must be an object');
    }

    return this.client.sendTransaction(
      sendTransactionRequest,
      convertObjectToMetadata(metadata),
      sendTransactionOptions,
    );
  }

  /**
   * @param {!GetTransactionRequest} getTransactionRequest
   * @param {?Object<string, string>} metadata
   * @return {Promise<!GetTransactionResponse>}
   */
  getTransaction(getTransactionRequest, metadata = {}) {
    if (!isObject(metadata)) {
      throw new Error('metadata must be an object');
    }

    return this.client.getTransaction(
      getTransactionRequest,
      convertObjectToMetadata(metadata),
      getTransactionOptions,
    );
  }

  /**
   *
   * @param {!GetBestBlockHeightRequest} getBestBlockHeightRequest
   * @param {?Object<string, string>} metadata
   * @returns {Promise<!GetBestBlockHeightResponse>}
   */
  getBestBlockHeight(getBestBlockHeightRequest, metadata = {}) {
    if (!isObject(metadata)) {
      throw new Error('metadata must be an object');
    }

    return this.client.getBestBlockHeight(
      getBestBlockHeightRequest,
      convertObjectToMetadata(metadata),
      getBestBlockHeightOptions,
    );
  }
}

module.exports = CorePromiseClient;
