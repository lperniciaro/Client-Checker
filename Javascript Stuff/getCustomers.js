
var XMLHttpRequest = require("xmlhttprequest").XMLHttpRequest;
var apiKey = "2da65fe30ee74aed8259771d4766172a";
var xhr2 = new XMLHttpRequest();
var xhr = new XMLHttpRequest();
var link = "https://app.atera.com/api/v3/customers?itemsInPage=";
xhr.open("GET", "https://app.atera.com/api/v3/customers?itemsInPage=1", true);
xhr.setRequestHeader("X-API-Key", apiKey);

var agents = new Array();

var totItems;

xhr.onreadystatechange = function(){
  if(this.readyState === 4 && this.status === 200){
    var json = JSON.parse(this.responseText);

    totItems = JSON.stringify(json['totalItemCount']);
    link = link + totItems;  //ADD THE PROPER COUNT TO HEADER

    xhr2.open("GET", link); //GET NEW REQUEST WITH FULL LIST
    xhr2.setRequestHeader("X-API-Key", apiKey);
    xhr2.send();

  }
}

xhr.send();

xhr2.onreadystatechange = function(){
  if(this.readyState === 4 & this.status ===200){
    var json = JSON.parse(this.responseText);
    console.log(json.items[2]["CustomerID"]);
    var test = [];
    for(var i = 0; i < json.items[0]["CustomerID"] ; i++){
      var text = JSON.stringify(json.items[i]['CustomerID']) + "," + JSON.stringify(json.items[i]["CustomerName"]);
      console.log(text);
      test.push(text);
    }
    var fs = require('fs');
    fs.writeFile("customerData.txt", test, function(err, result){
      if(err) console.log('error', err);
    });
  }
}

var test = prompt("eggs");
console.log(test);
//AUTH Symantec data


/*
WRITING THE DATA
var data = JSON.stringify(json);
var fs = require('fs');

fs.writeFile("file.json", data, function(err, result){
      if(err) console.log('error', err);
    });
*/

