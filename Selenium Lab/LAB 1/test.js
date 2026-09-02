const {Builder, By, until} = require('selenium-webdriver');

(async function ecommerceTests() {
    let driver = await new Builder().forBrowser('chrome').build();

    try {
        // Open Website
        await driver.get('https://www.saucedemo.com/');
        console.log(" Website opened");

        // ---------- LOGIN TEST ----------
        await driver.findElement(By.id('user-name')).sendKeys('standard_user');
        await driver.findElement(By.id('password')).sendKeys('secret_sauce');
        await driver.findElement(By.id('login-button')).click();

        await driver.wait(until.elementLocated(By.className('title')), 5000);
        let titleText = await driver.findElement(By.className('title')).getText();
        console.log(titleText.toLowerCase().includes("products") ? " Login Passed" : " Login Failed");

        // ---------- SEARCH / VIEW PRODUCT ----------
        let firstProduct = await driver.findElement(By.className('inventory_item_name'));
        let productName = await firstProduct.getText();
        console.log(" Found Product: " + productName);
        await firstProduct.click();

        // ---------- ADD TO CART ----------
        await driver.wait(until.elementLocated(By.css('.btn_primary.btn_inventory')), 5000);
        await driver.findElement(By.css('.btn_primary.btn_inventory')).click();
        console.log(" Product Added to Cart");

        // ---------- CHECKOUT ----------
        await driver.findElement(By.className('shopping_cart_link')).click();
        await driver.wait(until.elementLocated(By.id('checkout')), 5000);
        await driver.findElement(By.id('checkout')).click();

        await driver.findElement(By.id('first-name')).sendKeys('John');
        await driver.findElement(By.id('last-name')).sendKeys('Doe');
        await driver.findElement(By.id('postal-code')).sendKeys('302017');
        await driver.findElement(By.id('continue')).click();

        await driver.findElement(By.id('finish')).click();
        let confirmText = await driver.findElement(By.className('complete-header')).getText();
        console.log(confirmText.includes("THANK YOU") ? " Checkout Successful" : " Checkout Failed");

    } catch (err) {
        console.log(" Error: " + err);
    } finally {
        await driver.quit();
    }
})();