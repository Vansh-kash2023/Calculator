// Function to update the display
function updateDisplay(value) {
    const display = document.querySelector('.display');
    if (display.innerText === '0') {
        display.innerText = value;
    } else {
        display.innerText += value;
    }
}

// Function to clear the display
function clearDisplay() {
    const display = document.querySelector('.display');
    display.innerText = '0';
}

// Function to handle the backspace functionality
function backspace() {
    const display = document.querySelector('.display');
    if (display.innerText.length > 1) {
        display.innerText = display.innerText.slice(0, -1);
    } else {
        display.innerText = '0';
    }
}

// Function to evaluate the expression
function evaluation() {
    const display = document.querySelector('.display');
    try {
        display.innerText = eval(display.innerText.replace(/x/g, '*'));
    } catch (error) {
        display.innerText = 'Error';
    }
}

// Event listeners for each button
document.querySelectorAll('.button').forEach(button => {
    button.addEventListener('click', function() {
        const id = this.id;
        if (id === 'clear') {
            clearDisplay();
        } else if (id === 'back') {
            backspace();
        } else if (id === 'result') {
            evaluation();
        } else if (id === 'add') {
            updateDisplay('+');
        } else if (id === 'sub') {
            updateDisplay('-');
        } else if (id === 'mul') {
            updateDisplay('*');
        } else {
            updateDisplay(this.innerText);
        }
    });
});
