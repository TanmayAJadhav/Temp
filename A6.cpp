'''def expertSystem():
print("Welcome to Employee performance expert system.")

questions=["Are you satisfiedwith your job","how likely are you to recommend this as a good workplace","Did you make professional connections here?","Were you treated fairly in the office?"]
sum=0
for i in questions:
    print(i,"\n")
    print("1. Not at all\t2. less likely\t3. Neutral\t4. Slightly\t5. Absoluitely\n")
    rating = int(input("Enter your choice: "))
    sum+=rating

if sum<=((len(questions)*5)/4):
    print("Not at all satisfied")
elif sum<=((len(questions)*5)/2):
    print("Not satisfied")
elif sum<=((len(questions)*5)*3/4):
    print("Satisfied")
elif sum<=((len(questions)*5)):
    print("More than Satisfied")


print("Thank you.")


expertSystem()
'''

# Have you experienced any loss of taste or smell?
# Are you experiencing muscle or body aches?
# Have you noticed any shortness of breath or difficulty breathing?
# Are you experiencing chest pain or tightness?
# Have you recently traveled to an area with a high number of COVID-19 cases?
# Have you been in close contact with someone who tested positive for COVID-19?
# Are you currently experiencing any gastrointestinal symptoms such as nausea, vomiting, or diarrhea?
# Have you noticed any skin rashes or unusual skin discoloration?
# Are you experiencing dizziness or lightheadedness?
# Have you had a recent loss of appetite?

QUESTIONS = [   
    'Do you have cough?',
    'Do you have a sore throat?',
    'Do you have a fever?',
    'Are you noticing any unexplained excessive sweating?',
    'Do you have an itchy throat?',
    'Do you have a runny nose?',
    'Do you have a stuffy nose?',
    'Do you have a headache?',
    'Do you feel tired without actually exhausting yourself?'
]


THRESHOLD = {
    'Mild': 30,
    'Severe': 50,
    'Extreme': 75
}


def expertSystem(questions, threshold):

    score = 0

    for question in questions:
        print(question+" (Y/N) ")
        ans = input("> ")
        if ans.lower() == 'y':
            print('On a scale of 1-10 how bad is it ?')
            ip = input('> ')
            while((not ip.isnumeric()) or int(ip) < 1 or int(ip) > 10):
                print('Enter a valid input !')
                ip = input('> ')
            score += int(ip)

    print()
    print()

    if score >= threshold['Extreme']:
        print("You are showing symptoms of having EXTREME COVID-19")
        print("Please call +91 8112233445 immediately to immediate assistance")
        print("Based on your symptoms, You will need Immediate Hospitalization")

    elif score >= threshold['Severe']:
        print("Based on your answers You are showing Symptoms of SEVERE COVID-19")
        print("You are advised to contact a COVID-19 Specialist ASAP")
        print("You are prescribed with Favipriavir, Dolo 650 / Crocin 500, Paracetamol, Brufane")
        print("Also coduct a COVID-19 Lab Test ASAP at your own convenience as this might be a false Positive")
        print()
        print()
        print("Lab Testing: https://www.metropolisindia.com/parameter/pune/covid-19-rt-pcr-test")

    elif score >= threshold['Mild']:
        print("Based on your answers You are showing Symptoms of VERY MILD COVID-19")
        print("Please Isolate yourself Immediately on a precautionary basis")
        print("As this has a possibility of being a false positive , please consider testing yourself")
        print("At home testing using Self-Testing kits is recommended , but you can get Lab Tests as well")
        print()
        print()
        print("Self testing : https://www.flipkart.com/mylab-coviself-covid-19-rapid-antigen-test-kit/p/itm4d34ea09cad97")
        print("Lab Testing  : https://www.metropolisindia.com/parameter/pune/covid-19-rt-pcr-test")

    else:
        print("You are Showing NO Symptoms of COVID-19")
        print("This might be a false negative, If you feel unsure , please get Tested")
        print("As this has a possibility of being a false negative , please consider testing yourself")
        print("At home testing using Self-Testing kits is recommended")
        print()
        print()
        print("Self testing : https://www.flipkart.com/mylab-coviself-covid-19-rapid-antigen-test-kit/p/itm4d34ea09cad97")

    print()
    print()
    print("For any further queries visit : https://www.aarogyasetu.gov.in/")
    print()
    print()


if '__main__' == __name__:

    print("\n\n\t\tWelcome To The COVID-19 EXPERT SYSTEM\n")
    print("\tNote : Please answer the following questions very honestly\n\n")
    expertSystem(QUESTIONS, THRESHOLD)
