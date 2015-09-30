$("#contentWrapper li").click(function() {
// 	console.log($(this).css("background-image"));

	//grabs the image url of that particular image
	imgUrl = $(this).css("background-image");

		//replaces the image url of the last image shown in the lightbox with the current image
		$("#lightbox").css("background-image", imgUrl);
		//shows the updated lightbox that has been hidden
		$("#dark").fadeIn();
		$("#lightbox").fadeIn("slow");
});

$("#lightbox").click(function(){
	//hides the lightbox so we can go back to the page
	$("#dark").fadeOut();
	$("#lightbox").fadeOut("slow");
});


