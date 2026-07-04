import paralleldots as pd
pd.set_api_key('81a702352a37cbee1f2f40a254ad362be703d2e7')

def ner(text):
    ner=pd.ner("text")  
    return ner  