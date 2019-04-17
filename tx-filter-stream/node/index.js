const TransactionsFilterStreamClient = require('./TransactionsFilterStreamClient');

const messages = require('./tx_filter_stream_pb');

module.exports = Object.assign( {
  TransactionsFilterStreamClient,
}, messages);
