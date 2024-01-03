
function addMessage(msg, classId) {
    message = document.createElement('li');
    message.innerText = msg;
    message.className = classId;
    list = document.getElementById('chat');
    list.appendChild(message);
}
