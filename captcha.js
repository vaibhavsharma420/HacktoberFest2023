// Generate a random CAPTCHA string
function generateCaptcha() {
  const characters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789';
  let captcha = '';

  for (let i = 0; i < 6; i++) {
    const randomIndex = Math.floor(Math.random() * characters.length);
    captcha += characters[randomIndex];
  }

  return captcha;
}

// Display the CAPTCHA on the page
function displayCaptcha() {
  const captchaElement = document.getElementById('captcha');
  const captchaText = generateCaptcha();
  captchaElement.textContent = captchaText;
}

// Validate the user's input
function validateCaptcha() {
  const captchaElement = document.getElementById('captcha');
  const captchaInput = document.getElementById('captchaInput');
  const resultElement = document.getElementById('result');

  const expectedCaptcha = captchaElement.textContent;
  const userCaptcha = captchaInput.value;

  if (expectedCaptcha === userCaptcha) {
    resultElement.textContent = 'CAPTCHA is valid!';
  } else {
    resultElement.textContent = 'CAPTCHA is invalid. Please try again.';
    displayCaptcha(); // Generate a new CAPTCHA for the user to try again
  }
}

// Initialize the CAPTCHA when the page loads
window.addEventListener('load', displayCaptcha);
