from selenium import webdriver
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

firefox_profile = webdriver.FirefoxProfile()
options = webdriver.FirefoxOptions() 
options.add_argument("start-maximized")
options.add_argument('disable-infobars')
driver = webdriver.Firefox(firefox_profile=firefox_profile)
driver.get("http://www.google.co.in")
print("Initial Page Title is : %s" %driver.title)
windows_before  = driver.current_window_handle
print("First Window Handle is : %s" %windows_before)
driver.execute_script("window.open('https://www.yahoo.com')")
WebDriverWait(driver, 10).until(EC.number_of_windows_to_be(2))
windows_after = driver.window_handles
new_window = [x for x in windows_after if x != windows_before][0]
driver.switch_to_window(new_window)
print("Page Title after Tab Switching is : %s" %driver.title)
print("Second Window Handle is : %s" %new_window)
