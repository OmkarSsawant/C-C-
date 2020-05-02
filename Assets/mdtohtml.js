

const bStyle = /\s?\*{2}\b(.*)\b\*{2}/g;
const iStyle = /\s?\*{1}\b(.*)\b\*{1}/g;
const biStyle = /\s?\*{3}\b(.*)\b\*{3}/g;
const h1Regx = /\s?^#{1}\s{1}(.*$)/g;
const h2Regx = /\s?^#{2}\s{1}(.*$)/g;
const h3Regx = /\s?^#{3}\s{1}(.*$)/g;
const h4Regx = /\s?^#{4}\s{1}(.*$)/g;
const h5Regx = /\s?^#{5}\s{1}(.*$)/g;
const h6Regx = /\s?^#{6}\s{1}(.*$)/g;

const imgRegX = /^\[!(\w+)\]\((.*)\)$/;
const linkRegX = /^\[(\w+)\]\((.*)\)$/;
const videoRegX = /^\[%(\w+)%\]\((.*)\)$/;

function createMarkDown(readMe) {
    var html = '';

    let lineSplitted = readme.split(/\n/);

    for (var sec of lineSplitted) {
        let dom = createDom(sec);
        html += dom;
    }
    return html;
}





function createDom(section) {
    if (h1Regx.test(section)) return createH1(section);
    else if (h2Regx.test(section)) return createH2(section);
    else if (h3Regx.test(section)) return createH3(section);
    else if (h4Regx.test(section)) return createH4(section);
    else if (h5Regx.test(section)) return createH5(section);
    else if (h6Regx.test(section)) return createH6(section);
    else if (imgRegX.test(section)) return createImg(section);
    else if (videoRegX.test(section)) return createVideo(section);
    else if (linkRegX.test(section)) return createLink(section);
    else if (iStyle.test(section)) return createBIStyle(section);
    else if (section == '') return '<br/>';
    else return createP(section);

}


function createH1(sec) {
    return sec.replace(h1Regx, "<h1 id=$1> $1 </h1>");
}
function createH2(sec) {
    return sec.replace(h2Regx, "<h2 id=$1> $1 </h2>");
}
function createH3(sec) {
    return sec.replace(h3Regx, "<h3 id=$1> $1 </h3>");
}
function createH4(sec) {
    return sec.replace(h4Regx, "<h4 id=$1> $1 </h4>");
}
function createH5(sec) {
    return sec.replace(h5Regx, "<h5 id=$1> $1 </h5>");
}
function createH6(sec) {
    return sec.replace(h6Regx, "<h6 id=$1> $1 </h6>");
}
function createP(sec) {
    return `<p id=${sec.substr(0, ((sec.length / 2) % 5)).trim()}> ${sec} </p>`;
}

function createImg(sec) {
    return sec.replace(imgRegX, "<img src=$2 alt=$1 id=$1/>");
}

function createVideo(sec) {
    return sec.replace(videoRegX, "<video src=$2 alt=$1 id=$1/>");
}

function createLink(sec) {
    return sec.replace(linkRegX, "<a href=$2  id=$1> $1 </a>");
}

function createBIStyle(section) {
    if (biStyle.test(section)) return "<b id=$1> <i id=$1> $1 </i> </b>";
    else if (bStyle.test(section)) return "<b id=$1> $1 </b>";
    else return "<i id=$1> $1 </i>"
}
// const label = "Converting MarkDown to html ";
// console.time(label);
// console.log(createMarkDown(readme));
// console.timeEnd(label);
 module.exports = createMarkDown;
