const CorePromiseClient = require('./clients/nodejs/CorePromiseClient');
const PlatformPromiseClient = require('./clients/nodejs/PlatformPromiseClient');

const protocCoreMessages = require('./clients/nodejs/core_protoc');
const protocPlatformMessages = require('./clients/nodejs/platform_protoc');

const getCoreDefinition = require('./lib/getCoreDefinition');
const getPlatformDefinition = require('./lib/getPlatformDefinition');

const {
  org: {
    dash: {
      platform: {
        dapi: {
          v0: pbjsCoreMessages,
        },
      },
    },
  },
} = require('./clients/nodejs/core_pbjs');

const {
  org: {
    dash: {
      platform: {
        dapi: {
          v0: pbjsPlatformMessages,
        },
      },
    },
  },
} = require('./clients/nodejs/platform_pbjs');

module.exports = Object.assign({
  CorePromiseClient,
  PlatformPromiseClient,
  getCoreDefinition,
  getPlatformDefinition,
  pbjs: Object.assign(
    {},
    pbjsCoreMessages,
    pbjsPlatformMessages,
  ),
}, protocCoreMessages, protocPlatformMessages);
