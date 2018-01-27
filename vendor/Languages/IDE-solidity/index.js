var InternalCallTree = require('./src/decoder/internalCallTree')
var SolidityProxy = require('./src/decoder/solidityProxy')
var localDecoder = require('./src/decoder/localDecoder')
var stateDecoder = require('./src/decoder/stateDecoder')
var CodeAnalysis = require('./src/analysis/staticAnalysisRunner')

module.exports = {
  InternalCallTree: InternalCallTree,
  SolidityProxy: SolidityProxy,
  localDecoder: localDecoder,
  stateDecoder: stateDecoder,
  CodeAnalysis: CodeAnalysis
}
