const { chromium } = require('playwright');

async function testDevice(deviceName, width, height) {

    console.log('Testing ' + deviceName);
    console.log('Screen size: ' + width + ' x ' + height);

    const browser = await chromium.launch({
        headless: false
    });

    const page = await browser.newPage({
        viewport: {
            width: width,
            height: height
        }
    });

    // Open website
    await page.goto('https://www.saucedemo.com/');

    console.log('Website opened');

    // Check login page
    const loginButton = await page.locator('#login-button').isVisible();

    if (loginButton) {
        console.log('Login page is visible');
    } else {
        console.log('Login page is not visible');
    }

    // Login
    await page.locator('#user-name').fill('standard_user');
    await page.locator('#password').fill('secret_sauce');
    await page.locator('#login-button').click();

    const productsTitle = await page.locator('.title').textContent();

    if (productsTitle === 'Products') {
        console.log('Login successful');
    } else {
        console.log('Login failed');
    }

    // Add product to cart
    await page.locator('#add-to-cart-sauce-labs-backpack').click();

    const cartCount = await page.locator('.shopping_cart_badge').textContent();

    if (cartCount === '1') {
        console.log('Product added to cart');
    } else {
        console.log('Product was not added to cart');
    }

    // Check responsive layout
    const screenWidth = await page.evaluate(() => window.innerWidth);
    const pageWidth = await page.evaluate(() => document.documentElement.scrollWidth);

    console.log('Screen width: ' + screenWidth);
    console.log('Page width: ' + pageWidth);

    if (pageWidth <= screenWidth) {
        console.log('Website is responsive');
    } else {
        console.log('Website has horizontal overflow');
    }

    // Take screenshot
    await page.screenshot({
        path: deviceName + '.png',
        fullPage: true
    });

    console.log('Screenshot saved');

    await browser.close();
}

(async () => {
    
    // Test mobile view
    await testDevice('Mobile', 390, 844);

    // Test tablet view
    await testDevice('Tablet', 768, 1024);

    // Test laptop view
    await testDevice('Laptop', 1366, 768);

    console.log('All tests completed');

})();