import pandas as pd

def valid_emails(users: pd.DataFrame) -> pd.DataFrame:
    pattern = r'^[a-zA-Z][a-zA-Z\d_.-]*@leetcode\.com$'
    users = users.query("mail.str.contains(@pattern)")
    return users