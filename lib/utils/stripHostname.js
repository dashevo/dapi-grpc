/**
 * Remove everything except (hostname/ip):port pair
 *
 * @param {string} hostname
 *
 * @returns {string}
 */
function stripHostname(hostname) {
  /**
   * Following regexp matches first hostname or ip port pair
   */
  const [match] = hostname.match(/(\w+:[0-9]+)|((?:[0-9]{1,3}\.){3}[0-9]{1,3}:[0-9]+)/);
  return match;
}

module.exports = stripHostname;
