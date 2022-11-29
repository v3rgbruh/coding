import React, { useState } from "react";
import { Button, Form } from "react-bootstrap";
import { useLocation, useNavigate } from "react-router-dom";

function SearchBox() {
  const [keyword, setKeyword] = useState("");
  let navigate = useNavigate();
  const location = useLocation();

  const submitHandler = (e) => {
    e.preventDefault();
    if (keyword) {
      navigate(`/?keyword=${keyword}&page=1`);
    } else {
      navigate(location, { replace: true });
    }
  };

  return (
    <Form onSubmit={submitHandler} inline="true" className="d-flex">
      <Form.Control
        type="text"
        name="q"
        onChange={(e) => setKeyword(e.target.value)}
        className="pt-1 pb-1"
      ></Form.Control>
      <Button type="submit" variant="outline-success" className="p-2 pt-1 pb-1">
        Submit
      </Button>
    </Form>
  );
}

export default SearchBox;
