// This is the aras code, pasted to help Prorigo Team.

function callback(results) {
    if (results != null) {
        if (results.replaceAll(" ","") == "") {
            aras.AlertError("Please Enter the Name for Baseline.");
        } else {
            if (inDom != null) {
                debugger;
                const contextID = inDom.getAttribute("id"); // parent cha id
                const inn = aras.newIOMInnovator();
               
                let baslineQD = inn.newItem("qry_QueryDefinition", "get");
                baslineQD.setID("92A3ED2BA14F4CDDAF60EF6C8089FBDD"); // --> Query Devfinition id
                baslineQD.setAttribute("levels","2");
                baslineQD = baslineQD.apply();

                // baselienQd -> Item of Query definition
                // parameter : contextItemID : parent item id ala

                const parameter = baslineQD.getItemsByXPath("Relationships/Item[@type='qry_QueryParameter' and name='contextItemID']");
                parameter.setProperty("value", contextID);
                baslineQD.setAction("qry_ExecuteQueryDefinition");
                baslineQD.setAttribute("levels","0");
               
                const contextBaselineQDResult =  baslineQD.apply();
                
                let constextRelationshipsStr = "<Result>";
                let contextRelationships = contextBaselineQDResult.node.selectSingleNode("Relationships");
               
                if (contextRelationships != null) {
                    contextRelationships = contextRelationships.children;
                    const contextRelationshipsCount = contextRelationships.length;
                   
                    if (contextRelationshipsCount != 0) {
                        const xmlSerializer = new XMLSerializer();
                       
                        for (let i = 0; i < contextRelationshipsCount; i++) {
                            const contextRelationshipNode = contextRelationships[i];
                            constextRelationshipsStr = constextRelationshipsStr + xmlSerializer.serializeToString(contextRelationshipNode) + ",";  
                        }
                       
                        constextRelationshipsStr = constextRelationshipsStr.slice(0, -1);
                        constextRelationshipsStr = constextRelationshipsStr + "</Result>";
                    }
                }
               
                let contextBaselineRel = inn.newItem("SYE_Context_Baseline", "add");
                contextBaselineRel.setProperty("source_id", contextID);
                contextBaselineRel.setProperty("name", results);
                contextBaselineRel.setProperty("baseline_text", constextRelationshipsStr);
                contextBaselineRel = contextBaselineRel.apply();
            }
        }
    }
}
const arasPrompt = aras.prompt("Enter the Name for Baseline:");
const titleTag = document.getElementsByClassName("aras-dialog__title");

if (inDom != null && titleTag.length != 0) {
    const itemKeyedName = inDom.selectSingleNode("keyed_name");
    titleTag[0].text = itemKeyedName != null ? itemKeyedName.text : "Context";  
}
arasPrompt.then(
    function(dialogResult) {
        callback(dialogResult);
    }
);