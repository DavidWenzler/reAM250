import pprint
import xml.dom.minidom
from xml.dom.minidom import Node
import yaml
from yaml.loader import SafeLoader

print("Markus Magic Mapper")

ModuleList = []
MappingList = []
ModuleTypeDescriptionList = []

GlobalTypeFile = open("..\..\..\..\Logical\Global.typ",'w')

#Read YAML for IO Module Information
ModuleTypeFile = open(".\IOModuleTypes.yml", 'r')
ModuleTypeYamlContent = yaml.load(ModuleTypeFile, Loader=SafeLoader)

GlobalTypeFile.write("TYPE\n")

for Module, TypeDescription in ModuleTypeYamlContent.items():
    GlobalTypeFile.write(f"{Module.replace('-', '_')}_TYP : STRUCT\n")
    
    
    MappingList = []

    for Variable, Type in TypeDescription.items():
        GlobalTypeFile.write(f"{Variable} : {Type};\n")
        CurrentMapping = {'Variable' : Variable, 'Type' : Type}
        MappingList.append(CurrentMapping)
        

    ModuleTypeDescription = {'Module' : Module, 'Mapping' : MappingList}
    ModuleTypeDescriptionList.append(ModuleTypeDescription)
    #ModuleTypeDescriptionList.append(MappingList)
    GlobalTypeFile.write("END_STRUCT;\n")


GlobalTypeFile.write("END_TYPE\n")
GlobalTypeFile.close()

#Read Hardware Tree
HardwareConfigurationFile = xml.dom.minidom.parse("..\..\Hardware.hw")

for node in HardwareConfigurationFile.getElementsByTagName("Module"):
   Type = node.getAttribute("Type")
   Name = node.getAttribute("Name")
   if Type.startswith("X20"):
        if not Type.startswith("X20TB"):
            if not Type.startswith("X20BM"):
                
                #print(Name,Type)
                
                CurrentModule = {'Name' : Name, 'Type' : Type}
                ModuleList.append(CurrentModule)
                
                
                
                    
                    
GlobalVariableFile = open("..\..\..\..\Logical\Global.var",'a')              
IoMapFile          = open("..\IoMap.iom", 'a')
      
GlobalVariableFile.write("(*SCRIPT GENERATED VARIABLES*)\n")
GlobalVariableFile.write("VAR\n")


#Create Global Variable and IO mapping
for CurrentModule in ModuleList:

    GlobalVariableFile.write(f"IOMapping_{CurrentModule['Name']} : {CurrentModule['Type'].replace('-', '_')}_TYP;\n")

    print(f"Name: {CurrentModule['Name']} - Module: {CurrentModule['Type']}")
    Target = CurrentModule['Type']
    IoMapFile.write("VAR_CONFIG\n")
    for CurrentType in ModuleTypeDescriptionList:
         #print(f"Module: {CurrentType['Module']}")
         
         if(CurrentType['Module'] == Target):
            
            
            for Datapoint in CurrentType['Mapping']:
                if(Datapoint['Type'] == 'BOOL'):
                    MapType = '%IX'
                elif(Datapoint['Type'] == 'SINT') or (Datapoint['Type'] == 'USINT'):
                    MapType = '%IB'
                elif(Datapoint['Type'] == 'INT') or (Datapoint['Type'] == 'UINT'):
                    MapType = '%IW'
                elif(Datapoint['Type'] == 'DINT') or (Datapoint['Type'] == 'UDINT'):
                    MapType = '%ID'
                else:
                    MapType = ''

                IoMapFile.write(f"::IOMapping_{CurrentModule['Name']}.{Datapoint['Variable']} AT {MapType}.\"{CurrentModule['Name']}\".{Datapoint['Variable']};\n")

            break
    IoMapFile.write("END_VAR\n")
    


IoMapFile.close()

GlobalVariableFile.write("END_VAR\n")
GlobalVariableFile.write("(***************************)\n")
GlobalVariableFile.close()




print("Ende")
