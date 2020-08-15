const core = require('./clients/web/core_grpc_web_pb');
const platform = require('./clients/web/platform_grpc_web_pb');

module.exports = Object.assign(
  { },
  core,
  platform,
);
