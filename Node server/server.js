const express = require('express');
var request=require('request');

var app = express();

app.use(express.static(__dirname + '/public'));

app.use(function (req, res, next) {
  res.setHeader('Access-Control-Allow-Origin', null);
  res.setHeader('Access-Control-Allow-Methods', 'GET, POST, OPTIONS, PUT, PATCH, DELETE');
  res.setHeader('Access-Control-Allow-Credentials', true);
  next();
});

app.get('/', (req, res) => {
  res.send(
   'Server up and running' 
  );
});

var a="Off";
var b="Off";
var c="Off";


//192.168.43.154 is the IP address of the NodeMCU for Switching.
app.get('/s1on', (req, res) => {
console.log('System 1 on');
a="On"
request('http://192.168.43.154/c1on', function (error, response, body) {
console.log('error:', error); // Print the error if one occurred
console.log('statusCode:', response && response.statusCode); // Print the response status code if a response was received
});
});
app.get('/s2on', (req, res) => {
console.log('System 2 on');
b="On"
request('http://192.168.43.154/c2on', function (error, response, body) {
console.log('error:', error); // Print the error if one occurred
console.log('statusCode:', response && response.statusCode); // Print the response status code if a response was received
});  
});
app.get('/s3on', (req, res) => {
console.log('System 3 on');
c="On"
request('http://192.168.43.154/c3on', function (error, response, body) {
console.log('error:', error); // Print the error if one occurred
console.log('statusCode:', response && response.statusCode); // Print the response status code if a response was received
});
});

app.get('/s1off', (req, res) => {
console.log('System 1 off');
a="Off";
request('http://192.168.43.154/c1off', function (error, response, body) {
console.log('error:', error); // Print the error if one occurred
console.log('statusCode:', response && response.statusCode); // Print the response status code if a response was received
});
});
app.get('/s2off', (req, res) => {
console.log('System 2 off');
b="Off";
request('http://192.168.43.154/c2off', function (error, response, body) {
console.log('error:', error); // Print the error if one occurred
console.log('statusCode:', response && response.statusCode); // Print the response status code if a response was received
});  
});
app.get('/s3off', (req, res) => {
console.log('System 3 off');
c="Off";
request('http://192.168.43.154/c3off', function (error, response, body) {
console.log('error:', error); // Print the error if one occurred
console.log('statusCode:', response && response.statusCode); // Print the response status code if a response was received
});
});


app.get('/reset', (req, res) => {
console.log('System reset.All components turned Off');
a="Off";b="Off";c="Off";
request('http://192.168.43.154/c1off');
request('http://192.168.43.154/c2off');
request('http://192.168.43.154/c3off');
}); 

app.get('/status', (req, res) => {
console.log('System status');
res.send({
  s1: a,
  s2: b,
  s3: c });
  
});



app.listen(8080,
  function() {console.log('Server is up on port 8080');}
);