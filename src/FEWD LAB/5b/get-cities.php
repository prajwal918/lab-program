<?php
$country = $_GET["country"];
// Simulate fetching cities based on the selected country
if ($country === "usa") {
$cities = array("New York", "Los Angeles", "Chicago");
} elseif ($country === "canada") {
$cities = array("Toronto", "Vancouver", "Montreal");
} else {
$cities = array();
}
echo json_encode($cities);
?>