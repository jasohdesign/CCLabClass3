var hoboChicButton = document.getElementById('hobo-chic')
var trashButton = document.getElementById('trash')
var rawButton = document.getElementById('raw')
var grungeButton = document.getElementById('grunge')

// console.log($('#hobo-chic').val());

var hoboChicFeed = new Instafeed ({
	get: 'tagged',
	tagName: 'hobochic',
	links: 'false',
	limit: '30',
	clientId: 'a81795c6d6054b33ac57b09642cc731a'
});

hoboChicButton.addEventListener('click', function() {
	hoboChicFeed.run();
});

var trashFeed = new Instafeed ({
	get: 'tagged',
	tagName: 'trash',
	links: 'false',
	limit: '30',
	clientId: 'a81795c6d6054b33ac57b09642cc731a'
});

trashButton.addEventListener('click', function() {
	trashFeed.run();
	$('#instafeed').empty();
});

var rawFeed = new Instafeed ({
	get: 'tagged',
	tagName: 'raw',
	links: 'false',
	limit: '30',
	clientId: 'a81795c6d6054b33ac57b09642cc731a'
});

rawButton.addEventListener('click', function() {
	rawFeed.run();
	$('#instafeed').empty();
});

var grungeFeed = new Instafeed ({
	get: 'tagged',
	tagName: 'grunge',
	links: 'false',
	limit: '30',
	clientId: 'a81795c6d6054b33ac57b09642cc731a'
});

grungeButton.addEventListener('click', function() {
	grungeFeed.run();
	$('#instafeed').empty();
});

