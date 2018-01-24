var express = require('express');
var router = express.Router();
var compile = require('../api/compile');

/* GET home page. */
router.get('/', function (req, res, next) {
  res.render('index', {title: 'Express'});
});

router.get('/compile/serpent', compile.serpent);

module.exports = router;
