# xml2json
simple tool (and header) to convert an XML into a JSON

##Build
```bash
mkdir BUILD
cd BUILD
cmake ..
make -j4
```
##Usage
```
./xml2json Test/test.xml 2
```
###output
```
{
  "children": [
    {
      "children": [
        {
          "attributes": [
            {
              "name": "Name",
              "value": "The First Test"
            }
          ],
          "children": [
            {
              "node_name": "SomeText",
              "value": "Some simple text"
            },
            {
              "node_name": "SomeMoreText",
              "value": "More text 1"
            },
            {
              "node_name": "SomeMoreText",
              "value": "More text 2"
            },
            {
              "attributes": [
                {
                  "name": "Format",
                  "value": "FooFormat"
                }
              ],
              "node_name": "Description",
              "value": "\nJust a dummy\n\nXml file.\n    "
            }
          ],
          "node_name": "Test",
          "value": ""
        },
        {
          "attributes": [
            {
              "name": "Name",
              "value": "Second"
            }
          ],
          "node_name": "Test",
          "value": ""
        }
      ],
      "node_name": "Tests",
      "value": ""
    }
  ],
  "node_name": "root",
  "value": ""
}
```
