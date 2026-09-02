// FOR BUTTON 1: changing para color
let para = document.getElementById("p"); //id se element access kr pehle
let btn1 = document.getElementById("btn1") //btn bhi kar liya as button ki mdad se apne ko colors change krne hais
console.log(btn1);

btn1.addEventListener("click", function(){ //ye hame kisi element pr koi specific event ho use detect krne and fir uspr function ki help se koi interactive ko add krne me help krta hai
    para.style.color = "red"
})



// FOR DIV: changing div color by hovering on button 2
let mainContent = document.getElementsByClassName("container")[0] // agar indexing nhi use krte hai to container class waale sbi ke sbi elements access honge as a collection, ek treeke se array ke roop me store hoga. Agar indexing use krte hai to us index ke according hi us particular class waale elements access honge.
console.log(mainContent);


mainContent.style.backgroundColor = "pink" //styling ke liye
mainContent.addEventListener("mouseover", function(){ //agar mainContent variable me jo id/class wala element hai, uspr agar mouse lekr jaaenge to neeche di gyi property apply hogi.
    mainContent.style.backgroundColor = "lightgreen"
})

mainContent.addEventListener("mouseleave", function(){ //agar mouse htayenge to ye hogi.
    mainContent.style.backgroundColor = "pink"
})



// FOR BUTTON 2: changing image by clicking button 3
let image = document.getElementById("img")
let btn2 = document.getElementById("btn2")
console.log(btn2);
btn2.addEventListener("click" , function(){ //click krenge to ek to us element ka attribute (jo likha hai jaise ki "src" hai yaha, vo print krwaya hai console pr)
    let att = image.getAttribute("src")
    console.log(att);
})
console.log(image); //image wala variable me jo hai vo print krwaya hai console me

// image.removeAttribute("src") //iska use kiya jaata hai koi bhi  attribute ko dom se remove krne ke liye (console me krke pta lagega)

btn2.addEventListener("click", function(){
    image.setAttribute("src", "3.png") //attribute set krne ke liye, if attribute nhi hoga to "src" attribute ban jaaega ek and if hai to vhi rhega and aage jo src me add ya modify krna hai vo ho jaaega.
})



//DOM ME KOI NEW ELEMENT (NODE) ADD KRENGE:
let newPara = document.createElement("p") //isse apne new element bna skenge
console.log(newPara);

// content add krne ke liye:
newPara.textContent = "This 'p' tag has been created with the help of JS!!"
console.log(newPara);

// attribute set krne ke liye:
newPara.setAttribute("id", "p2")
console.log(newPara);

// jo ab new tag bnaya hai JS se uske content ko show krne ke liye following ways use krenge:
// and content apne ko jis jgh me add karna hai jaise div me main body me, to uske according variable use krenge
mainContent.appendChild(newPara) // last me add krne ke liye
console.log(newPara);

mainContent.prepend(newPara) // sbse upr add krne ke liye
console.log(newPara);

document.body.prepend(newPara) // directly body me add krne ke liye, div ke bahar starting me
console.log(newPara);

document.body.appendChild(newPara) // directly body me add krne ke liye, div ke bahar end me
console.log(newPara);
// neeche se hi ye hoga according to precedence if same type of properties hogi to.